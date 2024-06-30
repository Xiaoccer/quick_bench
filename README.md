# Usage

## Clone

```shell
git clone --recurse-submodules https://github.com/Xiaoccer/quick_bench.git
```

## Write benchmark

Write your own benchmark test cases in the `benchmark` directory and add corresponding files in `benchmark/CMakeLists.txt`.

## Configure

```shell
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B "build"
```

*Note:* Compilation defaults to using C++17 and -O3 optimization level.

## Compile

```shell
cd build && make -j && make install
```

The binaries can be found in the `build/output` directory. The `compare.py` is also located there.

To use the `compare.py`, ensure Python 3.10 or above is installed. Install the required packages using pip:

```shell
pip3 install -r requirements.txt
```

## Enjoy using the project!
