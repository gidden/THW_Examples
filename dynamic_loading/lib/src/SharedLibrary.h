
#include "Library.h"

class SharedLibrary : public Library {
 public:
  SharedLibrary();
  ~SharedLibrary();
  
  int counter();
  
 private:
  int counter_;
};
