#include "SharedLibrary.h"

using namespace std;

SharedLibrary::SharedLibrary() : counter_(1) {
  string name = "I'm a shared library!" + Library::protected_str_;
  setName(name);
}

SharedLibrary::~SharedLibrary() {}

int SharedLibrary::counter() {return counter_;}

extern "C" Library* constructSharedLibrary() {
  return new SharedLibrary();
}

extern "C" void destructSharedLibrary(Library* lib) {
  delete lib;
}
