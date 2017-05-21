PROJECT(UnitTest)
	SET(SRCS
	helperFun.hpp
	helperFun.cpp
	HammingUnitTest.cpp
	)
	ADD_EXECUTABLE(UnitTest ${SRCS})
	
INCLUDE_DIRECTORIES(${HAMMING_DIR})
LINK_DIRECTORIES(${LIB_DIR})

TARGET_LINK_LIBRARIES(UnitTest
  ${LIB_DIR}/${CMAKE_BUILD_TYPE}/HammingToolbox.lib
  )
