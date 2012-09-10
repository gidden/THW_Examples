rm -rf build && mkdir build && cd build;
cmake ../src -DCMAKE_INSTALL_PREFIX=../../install -DLIB_DIR=../../install && make -j3 && make install