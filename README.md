# My_Class_Time
 To run not with tests
 
```
 cmake -S. -Bbuild -DBUILD_MOCK=OFF --fresh
 cmake --build build
 ./build/Debug/kvadraturawn.exe
```

 To run with tests
 
```
 cmake -S. -Bbuild -DBUILD_MOCK=OFF --fresh
 cmake --build build
 cd build/test/
 ctest
 ./Debug/test_time_app
```
 
