#pragma once

#include<filesystem>

namespace fs = std::filesystem;

struct arguments {
	fs::path input;
	fs::path cpp;
	fs::path bin;
	bool output_cpp = false;
	bool output_bin = false;
	bool error = false;
};

arguments parse_args(int argc, char** argv);
