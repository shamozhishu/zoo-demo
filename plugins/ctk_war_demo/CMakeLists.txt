﻿###########################################################################
#                                                                         #
#                                ctk_war_demo                             #
#                                                                         #
###########################################################################
project(ctk_war_demo)
set(OUT_NAME ctk_war_demo)
SET(CMAKE_DEBUG_POSTFIX "")
set(PLUGIN_export_directive "ctk_war_demo_EXPORT")

IF(QT_INCLUDES)
	include_directories(${QT_INCLUDES})
ENDIF()

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

set(PLUGIN_SRCS
	VisualDemo.h
	DemoActivator.h
	
	VisualDemo.cpp
	DemoActivator.cpp
)

# Files which should be processed by Qts moc
set(PLUGIN_MOC_SRCS
	DemoActivator.h
)

# Qt Designer files which should be processed by Qts uic
set(PLUGIN_UI_FORMS
)

# QRC Files which should be compiled into the plugin
set(PLUGIN_RESOURCES
)

#Compute the plugin dependencies
ctkFunctionGetTargetLibraries(PLUGIN_target_libraries)

ctkMacroBuildPlugin(
	NAME ${PROJECT_NAME}
	EXPORT_DIRECTIVE ${PLUGIN_export_directive}
	SRCS ${PLUGIN_SRCS}
	MOC_SRCS ${PLUGIN_MOC_SRCS}
	TARGET_LIBRARIES ${PLUGIN_target_libraries}
	${Qt5Core_LIBRARIES}
	${Qt5Xml_LIBRARIES}
	${Qt5OpenGL_LIBRARIES}
	${Qt5Gui_LIBRARIES}
	${Qt5Widgets_LIBRARIES}
	debug zood optimized zoo
	debug zooCmdLoaderd optimized zooCmdLoader
)

IF (WIN32)
add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${plugin_RUNTIME_output_dir}/$<CONFIGURATION>/lib${lib_name}.dll"
        "${CMAKE_BINARY_DIR}/bin/$<CONFIGURATION>/plugins"
)
ENDIF()
