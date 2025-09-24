cmake_minimum_required(VERSION 3.22)
set(PROJECT_NAME "realm")

project(${PROJECT_NAME} LANGUAGES CXX)

set(PLUGIN_NAME "realm_plugin")

#make cmake output visible in build log file
set(CMAKE_VERBOSE_MAKEFILE TRUE CACHE BOOL "" FORCE)

# Android 16KB page support configuration
if(ANDROID)
    message(STATUS "Configuring for Android ${CMAKE_ANDROID_ARCH_ABI}")

    # Set minimum API level for 16KB page support
    if(NOT DEFINED CMAKE_ANDROID_API OR CMAKE_ANDROID_API LESS 23)
        set(CMAKE_ANDROID_API 23)
    endif()

    # Add 16KB page alignment for 64-bit architectures
    if(CMAKE_ANDROID_ARCH_ABI STREQUAL "arm64-v8a" OR CMAKE_ANDROID_ARCH_ABI STREQUAL "x86_64")
        message(STATUS "Adding 16KB page alignment for ${CMAKE_ANDROID_ARCH_ABI}")
        add_compile_definitions(_FILE_OFFSET_BITS=64)
        add_link_options(-Wl,-z,max-page-size=16384)

        # Ensure proper segment alignment
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,max-page-size=16384")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,max-page-size=16384")
    endif()
endif()

add_library(${PLUGIN_NAME} SHARED "realm_plugin.cpp")

# print cmake variables
#function(print_directory_variables dir)
#    # Dump variables:
#    get_property(_variableNames DIRECTORY ${dir} PROPERTY VARIABLES)
#    list (SORT _variableNames)
#    foreach (_variableName ${_variableNames})
#        get_directory_property(_variableValue DIRECTORY ${dir} DEFINITION ${_variableName})
#        message(STATUS "DIR ${dir}: ${_variableName}=${_variableValue}")
#    endforeach()
#endfunction(print_directory_variables)
#
#print_directory_variables(.)