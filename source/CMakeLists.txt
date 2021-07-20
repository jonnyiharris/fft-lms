# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${lms_SOURCE_DIR}/include/*.hpp")
set(SOURCE_FILES
	"dft.cpp"
	"fft.cpp"
	)
set(HEADER_FILES
	"${lms_SOURCE_DIR}/include/dft.hpp"
	"${lms_SOURCE_DIR}/include/fft.hpp"
	)


add_library(ft ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(ft PUBLIC ../include)
