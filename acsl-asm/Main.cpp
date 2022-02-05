#include "ArgumentParser.h"
#include "Parser.h"
#include "Util.h"

#include<cstdio>

int main(int argc, char** argv) {
	arguments args = parse_args(argc, argv);
	if (args.error) return 1;

	auto c = get_c(args.input);

	fs::path c_file = args.output_c ? args.c : fs::path(args.input.stem().string() + ".c");
	write_file(c_file, c);

	fs::path bin_file = args.output_bin ? args.bin : fs::path(args.input.stem().string() + ".exe");
	string gnu = "g++ -o " + bin_file.string() + " " + c_file.string();
	system(gnu.c_str());

	if (!args.output_c) remove(c_file.string().c_str());

	if (args.execute) system(bin_file.string().c_str());

	if (!args.output_bin) remove(bin_file.string().c_str());
}
