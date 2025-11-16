cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET "IamHerePlugin")
add_definitions(-DNOMINMAX)
add_definitions(-DTBB_USE_DEBUG)

project( 
    ${TARGET}
    LANGUAGES CXX C
)

add_library( ${TARGET} SHARED
    IamHerePlugin.cpp
    IamHerePlugin.h
    IamHere.cpp
    IamHere.h
)

target_link_directories( 
    ${TARGET}
    PRIVATE 
    ${USD_LIBRARY_DIR}
)

target_link_libraries(
    ${TARGET}
    PUBLIC
    ${USD_LIBS}
)

install(
    TARGETS 
    ${TARGET} 
    DESTINATION 
    ${CMAKE_INSTALL_PREFIX}/plugins
)

install(
    FILES 
    ${CMAKE_SOURCE_DIR}/IamHere/plugInfo.json 
    DESTINATION 
    ${CMAKE_INSTALL_PREFIX}/plugins/${TARGET}/resources 
)
