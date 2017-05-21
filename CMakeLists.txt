cmake_minimum_required(VERSION 3.2)


SET (LIB_DIR ${CMAKE_SOURCE_DIR}/bin CACHE INTERNAL "Lib directory")	
SET(HAMMING_DIR ${CMAKE_SOURCE_DIR}/HammingToolbox CACHE INTERNAL "Source directory")
INCLUDE_DIRECTORIES(${HAMMING_DIR})


PROJECT(HammingTest)
	SET(SRCS
	HammingTest.cpp
	)
	ADD_EXECUTABLE(HammingTest ${SRCS})

SET (CMAKE_BUILD_TYPE Debug CACHE INTERNAL "Configuration")	
OPTION(BUILD_RELEASE "Build Release." OFF)
IF (BUILD_RELEASE)
   SET (CMAKE_BUILD_TYPE Release)
ENDIF(BUILD_RELEASE)

add_subdirectory(HammingToolbox)
add_subdirectory (UnitTest)

TARGET_LINK_LIBRARIES(HammingTest
  ${LIB_DIR}/${CMAKE_BUILD_TYPE}/HammingToolbox.lib
  )
