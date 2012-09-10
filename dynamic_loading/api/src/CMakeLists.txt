cmake_minimum_required (VERSION 2.8)

# This project name is shared_lib.
project (LIB_LIB)

# Direct any out-of-source builds to this directory
SET( LIB_LIB_SRC_DIR ${CMAKE_SOURCE_DIR} )

# set module path
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

# This makes all the libraries build as SHARED
SET(BUILD_SHARED_LIBS true)

# Setup build locations.
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LIB_LIB_BINARY_DIR}/bin)
endif()
if(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_LIB_BINARY_DIR}/lib)
endif()
if(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_LIB_BINARY_DIR}/lib)
endif()

# Includes the directories in which there are source files. 
SET(LIB_LIB_INCLUDE_DIR
  ${LIB_LIB_SRC_DIR}
  )

# Add any new core source files to this list.
SET( LIBRARY_SRC
  Library.cpp
  )

# Add any new core source files to this list.
SET( LIBRARY_INCL
  Library.h
  )
 
# include all the directories we just found
INCLUDE_DIRECTORIES( ${LIBRARY_INCLUDE_DIR} )

# Build the Library library from the SHAREDLIBRARY_SRC source files
ADD_LIBRARY( Library ${LIBRARY_SRC} )
TARGET_LINK_LIBRARIES( Library dl ${LIBS} )

#install the files
install(TARGETS Library DESTINATION lib)
install(FILES ${LIBRARY_INCL} DESTINATION include/Library)
