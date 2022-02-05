#pragma once

#include<filesystem>
#include<string>

namespace fs = std::filesystem;

using std::string;

string get_c(fs::path in);
