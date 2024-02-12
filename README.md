### Многопоточный вариант bulk

##### Install:
```
sudo apt install ./mbulk-0.0.7-Linux.deb
```

##### Build:
```
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --target install --parallel <jobs>
```
`libasync.so`, `async.hpp`, `cmake`-файлы и пример `mbulk` находятся в `../install`

##### Docs:
https://notzahar.github.io/mbulk/
