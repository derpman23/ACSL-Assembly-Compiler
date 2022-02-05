#include "ArgumentParser.h"
#include "Parser.h"

int main(int argc, char** argv) {
	arguments args = parse_args(argc, argv);
	if (args.error) return 1;

	auto c = get_c(args.input);
}
