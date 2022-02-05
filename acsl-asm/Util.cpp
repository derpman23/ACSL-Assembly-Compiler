#include "Util.h"

#include<fstream>

void write_file(fs::path out, string data) {
	std::ofstream fout(out);
	
	if (fout.is_open()) {
		fout << data;
		fout.close();
	}
}
