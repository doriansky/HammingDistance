SET (LIBRARY_OUTPUT_PATH ${LIB_DIR})

PROJECT(HammingToolbox)
	SET(SRCS
	HammingToolbox.hpp
	HammingToolbox.cpp
	)
	ADD_LIBRARY(HammingToolbox ${SRCS})

