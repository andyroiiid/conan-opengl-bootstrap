# conan-opengl-bootstrap
a minimal example for building OpenGL applications with conan and CMake

## If you don't know what conan is(Why are you here in the first place?)
https://conan.io

## Add Bincrafters repo to conan
This example is using conan repos from [Bincrafters](https://bintray.com/bincrafters/public-conan) (GitHub: https://github.com/bincrafters).
```
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan 
```

## Install conan packages
### If you are using CLion
```
conan install . -s build_type=Debug --install-folder=cmake-build-debug --build=outdated
```
### Otherwise
Please refer to https://docs.conan.io/en/latest/integrations/cmake.html
