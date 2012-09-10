#include <dlfcn.h>
#include <iostream>
#include <string>
#include <cstdlib>

#include "Library.h"

typedef Library* create_t();
typedef void destroy_t(Library*);

using namespace std;

int main() {

  string path = "/home/gidden/sandbox/dynamic-loading/install/lib/libSharedLibrary.so";

  cout << "opening library at: " << path << endl;

  /* opening */
  void * lib = dlopen(path.c_str(),RTLD_LAZY);

  if (!lib)
    cout << "catching errors: " << dlerror() << endl;
  dlerror(); // reset

  cout << "open library at address: " << lib << endl;
  cout << "accessing public string: " << Library::public_str << endl;
  cout << endl << endl;
  /* -- */

  /* constructor */
  create_t * constructor = (create_t*) dlsym(lib,"constructSharedLibrary");

  if (!constructor)
    cout << "Unable to load module constructor: " << dlerror() << endl;
  cout << "Constructor address: " << constructor << endl;
  dlerror(); // reset
  /* -- */

  /* destructor */
  destroy_t * destructor = (destroy_t*) dlsym(lib,"destructSharedLibrary");

  if (!destructor)
    cout << "Unable to load module destructor: " << dlerror() << endl;
  cout << "Destructor address: " << destructor << endl;
  dlerror(); // reset
  /* -- */

  /* manipulate object */
  Library * libobj = constructor();
  cout << "Library object constructed with address: " << libobj << endl;
  cout << "Library constructed named: " << libobj->name() << endl;
  destructor(libobj);
  cout << "Library destructed." << endl;
  cout << endl << endl;
  /* -- */

  /* close libobjrary */
  int exit_code = dlclose(lib);
  if (exit_code != 0)
    cout << "Exit error: " << dlerror() << endl;
  dlerror(); // reset
  cout << "library closed with exit code: " << exit_code << endl;
  /* -- */

  return 0;
}


  // /* test new/delete usage */
  // Library * newlib = new Library();
  // cout << "new lib pre destruct: " << newlib << endl;
  // if (newlib) {
  //   cout << "newlib pointer exists" << endl;
  // }
  // else {
  //   cout << "newlib pointer does not exist" << endl;
  // }
  // delete libobj;
  // cout << "new lib post destruct: " << newlib << endl;
  // if (newlib) {
  //   cout << "newlib pointer exists" << endl;
  // }
  // else {
  //   cout << "newlib pointer does not exist" << endl;
  // }
  // cout << endl << endl;
  // /* -- */
