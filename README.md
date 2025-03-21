# Google Test

> This repository is a template for anyone to start writing their own
> unit test using googletest library with cmake.

## Usage

Populate the code you want to test in src and include.
Add your test cases in the tests directory.


## Building

Build using the `cmake` command.  
```bash
cmake -S . -B build
cmake --build build
```

## Running

I use ctest as a helper to run the unit test.
More about it [here](https://github.com/BruceChanJianLe/ctest).
the ctest command.

```bash
ctest --test-dir build
```
