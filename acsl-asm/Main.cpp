#include "ArgumentParser.h"

int main(int argc, char** argv) {
	arguments args = parse_args(argc, argv);
	if (args.error) return 1;
}