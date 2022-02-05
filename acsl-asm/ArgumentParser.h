#pragma once

#include<filesystem>

namespace fs = std::filesystem;

struct arguments {
	fs::path input;
	fs::path c;
	fs::path bin;
	bool output_c = false;
	bool output_bin = false;
	bool error = false;
};

arguments parse_args(int argc, char** argv);
