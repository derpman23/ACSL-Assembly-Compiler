#pragma once

#include<filesystem>
#include<string>

namespace fs = std::filesystem;

using std::string;

void write_file(fs::path out, string data);
