

## How to use

```
cmake -DCMAKE_BUILD_TYPE:STRING=Debug -G "Visual Studio 17 2022" -T host=x64 -A x64 ..
```

```
cmake --build . --config Debug --target ALL_BUILD -j 18 --
```