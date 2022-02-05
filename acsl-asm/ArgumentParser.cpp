#include<cstring>
#include<iostream>

#include "ArgumentParser.h"

using std::cerr;
using std::endl;

arguments parse_args(int argc, char** argv) {
	arguments args;
	bool input_set = false;

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-n") == 0) args.execute = false;
		else if (strcmp(argv[i], "-c") == 0) {
			if (++i == argc) {
				cerr << "Please specify an output file." << endl;
				args.error = true;
				return args;
			}

			fs::path path(argv[i]);

			if (!path.has_extension() || (path.extension().string() != ".c" && path.extension().string() != ".cpp")) {
				cerr << "Invalid extension \"" << path.extension().string() << "\". Please specify a path with extension \".c\" or \".cpp\"" << endl;
				args.error = true;
				return args;
			}

			args.output_c = true;
			args.c = path;
		}
		else if (strcmp(argv[i], "-bin") == 0) {
			if (++i == argc) {
				cerr << "Please specify an output file." << endl;
				args.error = true;
				return args;
			}

			fs::path path(argv[i]);

			if (!path.has_extension() || (path.extension().string() != ".bin" && path.extension().string() != ".exe")) {
				cerr << "Invalid extension \"" << path.extension().string() << "\". Please specify a path with extension \".bin\" or \".exe\"" << endl;
				args.error = true;
				return args;
			}

			args.output_bin = true;
			args.bin = path;
		}
		else {
			if (!fs::exists(argv[i]) || !fs::is_regular_file(argv[i])) {
				std::cerr << "File \"" << argv[i] << "\" not found." << std::endl;
				args.error = true;
				return args;
			}

			fs::path path(argv[i]);

			if (!path.has_extension() || path.extension().string() != ".asm") {
				cerr << "Invalid extension \"" << path.extension().string() << "\". Please specify a path with extension \".asm\"" << endl;
				args.error = true;
				return args;
			}

			args.input = path;
			input_set = true;
		}
	}

	if (!input_set) {
		cerr << "Please specify an input file." << endl;
		args.error = true;
	}

	return args;
}
