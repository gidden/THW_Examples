cmake_minimum_required (VERSION 2.8)

# This project name is shared_lib.
project (SHARED_LIB)

# Direct any out-of-source builds to this directory
SET( SHARED_LIB_SRC_DIR ${CMAKE_SOURCE_DIR} )

# set module path
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

# This makes all the libraries build as SHARED
SET(BUILD_SHARED_LIBS true)

# Setup build locations.
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SHARED_LIB_BINARY_DIR}/bin)
endif()
if(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SHARED_LIB_BINARY_DIR}/lib)
endif()
if(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SHARED_LIB_BINARY_DIR}/lib)
endif()

# Add any new core source files to this list.
SET( SHARED_LIB_SRC
  SharedLibrary.cpp
  )

# Add any new core source files to this list.
SET( SHARED_LIB_INCL
  SharedLibrary.h
  )

# find blas and link to it
FIND_PACKAGE( LIBRARY REQUIRED )
set(TOTAL_INCL . ${LIB_INCLUDE_DIR}) #${SHARED_LIB_INCL}
set(LIBS ${LIBS} ${LIB_LIB})
 
# include all the directories we just found
INCLUDE_DIRECTORIES( ${TOTAL_INCL} )

# Build the SharedLibrary library from the SHAREDLIBRARY_SRC source files
ADD_LIBRARY( SharedLibrary ${SHARED_LIB_SRC} )
TARGET_LINK_LIBRARIES( SharedLibrary dl ${LIBS} )

#install the files
install(TARGETS SharedLibrary DESTINATION lib)
install(FILES ${SHARED_LIB_INCL} DESTINATION include/SharedLibrary)
