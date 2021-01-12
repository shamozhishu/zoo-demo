###########################################################################
#                                                                         #
#                               zooCmd_osg-fc                             #
#                                                                         #
###########################################################################
set(OUT_NAME zooCmd_osg-fc)

include_directories("${3RD_PARTY_DIR}/include")
include_directories("${OSG_DIR}/include")
include_directories("${OSGEARTH_DIR}/include")

link_directories("${3RD_PARTY_DIR}/lib")
link_directories("${OSG_DIR}/lib")
link_directories("${OSGEARTH_DIR}/lib")

include(Find3rdPartyDependencies)

if(ZOO_DIR)
	include_directories(${ZOO_DIR}/include)
	link_directories(${ZOO_DIR}/lib)
else()
	message(FATAL_ERROR "ZOO_DIR need to set!!!")
endif()

file(GLOB ZOOCMD_PLUGIN_LIB_H "*.h")
file(GLOB ZOOCMD_PLUGIN_LIB_CPP "*.cpp")
    
add_library(
	${OUT_NAME} SHARED 
	${ZOOCMD_PLUGIN_LIB_H}
	${ZOOCMD_PLUGIN_LIB_CPP}
)
ADD_DEFINITIONS(-DNEED_OSGEARTH_LIBRARY)
target_link_libraries(
	${OUT_NAME}
	debug zood optimized zoo
	debug zooCmdd optimized zooCmd
)

INSTALL(TARGETS ${OUT_NAME} RUNTIME DESTINATION bin/$<CONFIGURATION>)
