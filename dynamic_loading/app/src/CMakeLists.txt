# This project name is cyclus.
PROJECT( APP )
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Direct any out-of-source builds to this directory
SET( APP_SRC_DIR ${CMAKE_SOURCE_DIR} )

# set module path
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

# This makes all the libraries build as SHARED
SET(BUILD_SHARED_LIBS true)

# Setup build locations.
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${APP_BINARY_DIR}/bin)
endif()
if(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${APP_BINARY_DIR}/lib)
endif()
if(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${APP_BINARY_DIR}/lib)
endif()

SET( APP_SRC
  app.cpp
  )

# find blas and link to it
FIND_PACKAGE( LIBRARY REQUIRED )
set(TOTAL_INCL . ${LIB_INCLUDE_DIR})
set(LIBS ${LIBS} ${LIB_LIB})
 
# include all the directories we just found
INCLUDE_DIRECTORIES( ${TOTAL_INCL} )

# Build the cyclus executable from the APP_SRC source files
ADD_EXECUTABLE( app ${APP_SRC} )
TARGET_LINK_LIBRARIES( app dl ${LIBS} )

INSTALL(TARGETS app
  RUNTIME DESTINATION bin
  COMPONENT app
  )
