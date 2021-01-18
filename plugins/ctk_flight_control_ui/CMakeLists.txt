###########################################################################
#                                                                         #
#                           ctk_flight_control_ui                         #
#                                                                         #
###########################################################################
project(ctk_flight_control_ui)
set(OUT_NAME ctk_flight_control_ui)
SET(CMAKE_DEBUG_POSTFIX "")
set(PLUGIN_export_directive "ctk_flight_control_ui_EXPORT")

FIND_PACKAGE(Qt5Svg)
IF(Qt5Svg_FOUND)
    include_directories(${Qt5Svg_INCLUDE_DIRS})
ENDIF()

IF(QT_INCLUDES)
	include_directories(${QT_INCLUDES})
ENDIF()

SET(QWT_INCLUDE_DIR "" CACHE PATH "Set to Qwt include path")
SET(QWT_LIBRARY "" CACHE FILEPATH "Set to Qwt release lib file")
SET(QWT_LIBRARY_DEBUG "" CACHE FILEPATH "Set to Qwt debug lib file")

if (QWT_INCLUDE_DIR)
	include_directories(${QWT_INCLUDE_DIR})
else()
	message(FATAL_ERROR "QWT_INCLUDE_DIR need to set!!!")
endif()

if (NOT QWT_LIBRARY)
	message(FATAL_ERROR "QWT_LIBRARY need to set!!!")
endif()
	
if (NOT QWT_LIBRARY_DEBUG)
	message(FATAL_ERROR "QWT_LIBRARY_DEBUG need to set!!!")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/qfi ${CMAKE_CURRENT_SOURCE_DIR}/qfi_widget)
ADD_DEFINITIONS(-D_USE_MATH_DEFINES)

IF(WIN32 AND NOT ANDROID)
	# CTK
	IF(3RD_PARTY_DIR)
		SET(CTK_DIR ${3RD_PARTY_DIR}/lib/ctk-0.1/CMake)
		FIND_PACKAGE(CTK REQUIRED)
		include_directories(
			${CTKCore_INCLUDE_DIRS}
			${CTKPluginFramework_INCLUDE_DIRS}
		)
		link_directories("${CTK_LIBRARY_DIR}")
	ELSE()
		message(FATAL_ERROR "3RD_PARTY_DIR need to set!!!")
	ENDIF()

	include_directories("${3RD_PARTY_DIR}/include")
	link_directories("${3RD_PARTY_DIR}/lib")
	include(Find3rdPartyDependencies)
else()
	FIND_PACKAGE(CTK)
	include_directories(
		${CTKCore_INCLUDE_DIRS}
		${CTKPluginFramework_INCLUDE_DIRS}
	)

	include_directories("${3RD_PARTY_DIR}/include")
	link_directories("${3RD_PARTY_DIR}/lib")
endif()

if(ZOO_DIR)
	include_directories(${ZOO_DIR}/include)
	link_directories(${ZOO_DIR}/lib)
else()
	message(FATAL_ERROR "ZOO_DIR need to set!!!")
endif()

file(GLOB BS_HEADERS "*.h")
file(GLOB MOC_HEADERS "qfi/*.h" "qfi_widget/*.h")
file(GLOB BS_SOURCES "*.cpp" "qfi/*.cpp" "qfi_widget/*.cpp")
file(GLOB BS_UI_FORMS "*.ui" "qfi_widget/*.ui")
file(GLOB BS_RESOURCES "*.qrc" "Resources/*.qrc")

set(PLUGIN_SRCS
	${BS_HEADERS}
	${BS_SOURCES}
	${MOC_HEADERS}
)

# Files which should be processed by Qts moc
set(PLUGIN_MOC_SRCS
	UIActivator.h
	MainWindow.h
	LogRecordWgt.h
	FlightVisualWgt.h
	FlightParamPanel.h
	FlightViewPanel.h
	FullScreenPanel.h
	SystemConfigPanel.h
	GroundCheckPanel.h
	LinkMonitorPanel.h
	MainViewPanel.h
	ServoElectricPanel.h
	NavAttitudePanel.h
	FlyingControlPanel.h
	RouteCmdPanel.h
	ParamCmdPanel.h
	DeviceStatePanel.h
	EngineSystemPanel.h
	DeviceMarkPanel.h
	${MOC_HEADERS}
)

# Qt Designer files which should be processed by Qts uic
set(PLUGIN_UI_FORMS
	${BS_UI_FORMS}
)

# QRC Files which should be compiled into the plugin
set(PLUGIN_RESOURCES
	${BS_RESOURCES}
)

#Compute the plugin dependencies
ctkFunctionGetTargetLibraries(PLUGIN_target_libraries)

ctkMacroBuildPlugin(
	NAME ${PROJECT_NAME}
	EXPORT_DIRECTIVE ${PLUGIN_export_directive}
	SRCS ${PLUGIN_SRCS}
	MOC_SRCS ${PLUGIN_MOC_SRCS}
	UI_FORMS ${PLUGIN_UI_FORMS}
	RESOURCES ${PLUGIN_RESOURCES}
	TARGET_LIBRARIES ${PLUGIN_target_libraries}
	${Qt5Core_LIBRARIES}
	${Qt5Xml_LIBRARIES}
	${Qt5OpenGL_LIBRARIES}
	${Qt5Gui_LIBRARIES}
	${Qt5Widgets_LIBRARIES}
	${Qt5Svg_LIBRARIES}
	debug zood optimized zoo
	debug zooCmdLoaderd optimized zooCmdLoader
	debug ${QWT_LIBRARY_DEBUG} optimized ${QWT_LIBRARY}
)

IF (WIN32)
add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${plugin_RUNTIME_output_dir}/$<CONFIGURATION>/lib${lib_name}.dll"
        "${CMAKE_BINARY_DIR}/bin/$<CONFIGURATION>/plugins"
)
ENDIF()
