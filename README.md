# COLA example module

## ExModule installation

```shell
$ cd ../
$ mkdir build
$ cd build
$ cmake ../COLA-min-example
$ cmake --build . --target install
``` 

Check ```CMakeLists.txt``` for an idea of installation process

## Program example

In ```test``` dir:

```shell
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```

If both COLA and ExModule installed right, on running the you should see:

```
Parsing XML file:
filter name: example_gen
params:
filter name: example_converter
params:
filter name: example_writer
params:
0, 0, 0
1, 1, 1
```