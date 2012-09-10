# lets define a variable called LIB_DIR

MESSAGE(STATUS "LIB_DIR hint is : ${LIB_DIR}")

FIND_PATH(LIB_INCLUDE_DIR Library.h
  HINTS "${LIB_DIR}/include/Library"
)
MESSAGE("\tFound the Library Include Path: ${LIB_INCLUDE_DIR}")

FIND_LIBRARY(LIB_LIB
  NAMES Library libLibrary
  HINTS "${LIB_DIR}/lib"
)
MESSAGE("\tFound the Library: ${LIB_LIB}")