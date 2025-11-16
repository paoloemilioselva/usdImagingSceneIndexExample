if(DEFINED USD_ROOT)
    message(STATUS "Using Pixar USD: ${USD_ROOT}")
    include(cmake/FindPixarUsd.cmake)
else()
    message(FATAL_ERROR "Set USD_ROOT to compile")
endif()

message(STATUS "Using Usd Schema Generator: ${USD_SCHEMA_GENERATOR}")