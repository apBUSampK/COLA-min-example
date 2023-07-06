# COLA example module

## ExModule installation

```shell
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
$ cmake --install .
``` 

No need for additional config flies! \
Check ```CMakeLists.txt``` for an idea of installation process

## Program example

In ```test``` dir:

```shell
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```

If both COLA and ExModule installed right, you should see:

```
0, 0, 0
1, 1, 1`
```