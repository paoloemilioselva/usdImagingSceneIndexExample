MESSAGE(STATUS "USD_VERSION = " ${USD_VERSION} )
MESSAGE(STATUS "USD_ROOT = " ${USD_ROOT} )
    
set(Python_ADDITIONAL_VERSIONS 3.11)
find_package(Python EXACT 3.11 COMPONENTS Interpreter Development)
include_directories( ${Python_INCLUDE_DIRS} )
message(STATUS "Python_FOUND:${Python_FOUND}")
message(STATUS "Python_VERSION:${Python_VERSION}")
message(STATUS "Python_Development_FOUND:${Python_Development_FOUND}")
message(STATUS "Python_INCLUDE_DIRS:${Python_INCLUDE_DIRS}")
message(STATUS "Python_LIBRARIES:${Python_LIBRARIES}")


get_filename_component(USD_INCLUDE_DIR ${USD_ROOT}/include ABSOLUTE)
get_filename_component(USD_LIBRARY_DIR ${USD_ROOT}/lib ABSOLUTE)

set(USD_LIBRARY_MONOLITHIC FALSE)

set(PXR_LIB_PREFIX "")

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(USD
    REQUIRED_VARS
        USD_INCLUDE_DIR
        USD_LIBRARY_DIR
    VERSION_VAR
        USD_VERSION
)

set (_usd_libs
    usd_boost
    usd_python
    usd_usdImagingGL
    usd_usdImaging
    usd_usdSkelImaging
    usd_usdHydra
    usd_hdx
    usd_hdSt
    usd_hd
    usd_glf
    usd_garch
    usd_pxOsd
    usd_usdRi
    usd_usdUI
    usd_usdShade
    usd_usdGeom
    usd_usdSkel
    usd_usdLux
    usd_usd
    usd_usdUtils
    usd_pcp
    usd_sdf
    usd_plug
    usd_js
    usd_ar
    usd_work
    usd_tf
    usd_kind
    usd_arch
    usd_vt
    usd_gf
    usd_hf
    usd_cameraUtil
    usd_trace
    usd_ts
)

include_directories(
    ${USD_INCLUDE_DIR}
)

set(USD_LIBS 
    ${Python_LIBRARIES}
    ${_usd_libs}
)

message(STATUS "USD_LIBS:${USD_LIBS}")