# ACSL Assembly Compiler
[![C++](https://img.shields.io/static/v1?label=C%2B%2B&message=v17&color=purple&link=https://docs.microsoft.com/en-us/cpp/?view=msvc-160)](https://docs.microsoft.com/en-us/cpp/?view=msvc-160) [![License](https://img.shields.io/badge/license-MIT-blue.svg?label=License&link=https://mit-license.org/)](./LICENSE)

This compiler is for assembly files in the ACSL format. It can convert asm files into C++ and binary files or simply execute the file.

## Options

| Option (* are required) | Flag | Description                                             |
| ----------------------- | ---- | ------------------------------------------------------- |
| *Input File             |      | Specify the input file with extension ".asm"            |
| Prevent execution       | -n   | Prevents the program from automatically executing.      |
| Compile to a C++ file   | -c   | Specify the output file with extension ".c" or ".cpp"   |
| Compile to a binary file| -bin | Specify the output file with extension ".bin" or ".exe" |

## License
This code is licensed under the [MIT License](./LICENSE).