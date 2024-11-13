# My_Class_Time
 To run not with tests
 
```
  cmake -S . -B build -DENABLE_TEST=OFF --fresh
  cmake --build build
 ./build/Debug/kvadraturawn.exe
```

 To run with tests
 
```
 cmake -S. -B build -DBUILD_MOCK=OFF -DENABLE_TEST=ON --fresh
 cmake --build build
 cd build/test/
 ctest
 ./Debug/test_time_app
```
 
