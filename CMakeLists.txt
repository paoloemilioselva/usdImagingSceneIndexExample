CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

message(STATUS "Using "$ENV{REZ_TBB_ROOT})
message(STATUS "Using "$ENV{REZ_BOOST_ROOT})
message(STATUS "Using "$ENV{REZ_USD_ROOT})

set( TBB_ROOT_DIR $ENV{REZ_TBB_ROOT} )
include(cmake/FindTBB.cmake)
include_directories( ${TBB_INCLUDE_DIRS} )

set( BOOST_ROOT $ENV{REZ_BOOST_ROOT} )
include_directories( ${BOOST_ROOT} )

set( USD_ROOT $ENV{REZ_USD_ROOT} )
include(cmake/FindUsd.cmake)


add_subdirectory(./IamHere)
