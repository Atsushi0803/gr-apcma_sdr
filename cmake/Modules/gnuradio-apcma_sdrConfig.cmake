find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_APCMA_SDR gnuradio-apcma_sdr)

FIND_PATH(
    GR_APCMA_SDR_INCLUDE_DIRS
    NAMES gnuradio/apcma_sdr/api.h
    HINTS $ENV{APCMA_SDR_DIR}/include
        ${PC_APCMA_SDR_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_APCMA_SDR_LIBRARIES
    NAMES gnuradio-apcma_sdr
    HINTS $ENV{APCMA_SDR_DIR}/lib
        ${PC_APCMA_SDR_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-apcma_sdrTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_APCMA_SDR DEFAULT_MSG GR_APCMA_SDR_LIBRARIES GR_APCMA_SDR_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_APCMA_SDR_LIBRARIES GR_APCMA_SDR_INCLUDE_DIRS)
