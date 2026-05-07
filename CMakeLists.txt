cmake_minimum_required(VERSION 3.16)

project(STimer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        if(CMAKE_CXX_COMPILER MATCHES "MinGW")
            set(PLATFORM_DIR "x86_64-MinGW")
        endif()
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        set(PLATFORM_DIR "x64-MSVC")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(PLATFORM_DIR "x64-Clang")
    endif()
elseif(APPLE)
    if(CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
        set(PLATFORM_DIR "arm64-macOS")
    else()
        set(PLATFORM_DIR "x86_64-macOS")
    endif()

    set(PLATFORM_LIBS
        "-Wl,-framework,Cocoa"
        "-Wl,-framework,Metal"
        "-Wl,-framework,UniformTypeIdentifiers"
        "-Wl,-framework,IOKit"
        "-Wl,-framework,AVFoundation"
        "-Wl,-framework,CoreMedia"
        "-Wl,-framework,CoreVideo"
        "-Wl,-framework,CoreAudio"
        "-Wl,-framework,AudioToolbox"
        "-Wl,-framework,QuartzCore"
        "-Wl,-framework,GameController"
        "-Wl,-framework,ForceFeedback"
        "-Wl,-weak_framework,CoreHaptics"
        "-Wl,-framework,Carbon"
        "-Wl,-framework,Security"
        "-Wl,-framework,Foundation"
    )

elseif(UNIX)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(PLATFORM_DIR "x86_64-linux-gcc")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(PLATFORM_DIR "x86_64-linux-clang")
    endif()
endif()

if(NOT PLATFORM_DIR)
    message(WARNING "Unknown platform, defaulting to x86_64-MinGW")
    set(PLATFORM_DIR "x86_64-MinGW")
endif()

if(NOT PLATFORM_LIBS)
    set(PLATFORM_LIBS "")
endif()

message(STATUS "Platform detected: ${PLATFORM_DIR}")

set(THIRD_PARTY_ROOT "${CMAKE_SOURCE_DIR}/ThirdParty")
set(THIRD_PARTY_LIB "${THIRD_PARTY_ROOT}/lib/${PLATFORM_DIR}")
set(THIRD_PARTY_BIN "${THIRD_PARTY_ROOT}/bin/${PLATFORM_DIR}")
set(THIRD_PARTY_INCLUDE "${THIRD_PARTY_ROOT}/include/${PLATFORM_DIR}")

include_directories(${THIRD_PARTY_INCLUDE})
include_directories("${CMAKE_SOURCE_DIR}/include")

link_directories(${THIRD_PARTY_LIB})

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    SDL3
    SDL3_image
    curl
    ${PLATFORM_LIBS}
)
