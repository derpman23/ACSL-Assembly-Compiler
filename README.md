# ACSL Assembly Compiler
[![C++](https://img.shields.io/static/v1?label=C%2B%2B&message=v17&color=purple&link=https://docs.microsoft.com/en-us/cpp/?view=msvc-160)](https://docs.microsoft.com/en-us/cpp/?view=msvc-160) [![License](https://img.shields.io/badge/license-MIT-blue.svg?label=License&link=https://mit-license.org/)](./LICENSE)

This compiler is for assembly files in the ACSL format. It can convert asm files into C++ and binary files or simply execute the file.

## Options

| Option (* are required) | Flag | Description                                             |
| ----------------------- | ---- | ------------------------------------------------------- |
| *Input File             |      | Specify the input file with extension ".asm"            |
| Compile to a C++ file   | -cpp | Specify the output file with extension ".cpp"           |
| Compile to a binary file| -bin | Specify the output file with extension ".bin" or ".exe" |