#include "Parser.h"

#include<fstream>
#include<map>
#include<set>
#include<sstream>

std::map<string, int> opcodes{ 
	{ "LOAD", 1 }, 
	{ "STORE", 2 }, 
	{ "ADD", 3 }, 
	{ "SUB", 4 },
	{ "MULT", 5 },
	{ "DIV", 6 },
	{ "BG", 7 },
	{ "BE", 8 },
	{ "BL", 9 },
	{ "BU", 10 },
	{ "READ", 11 },
	{ "PRINT", 12 },
	{ "DC", 13 },
	{ "END", 14 }
};

bool is_int(string s) {
	try {
		stoi(s);
		return true;
	}
	catch (...) {
		return false;
	}
}

string get_c(fs::path in) {
	std::ifstream fin(in);
	string code = "#include<stdio.h>\nint main(){int acc=0;";

	if (fin.is_open()) {
		string line, body = "";
		std::set<string> defined;
		while (std::getline(fin, line)) {
			std::stringstream ss(line);
			string fields[3], s;
			int idx = 0;
			
			while (ss >> s) {
				if (idx != 2 && opcodes[s]) {
					fields[1] = s;
					idx = 2;
					continue;
				}
				
				if (idx < 3) fields[idx++] = s;
			}

			if (!fields[2].empty() && fields[2][0] == '=' && is_int(fields[2].substr(1))) fields[2] = fields[2].substr(1);

			switch (opcodes[fields[1]]) {
			case 1:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "acc=" + fields[2] + ";";
				break;
			case 2:
				if (!fields[0].empty()) body += fields[0] + ":";
				defined.insert(fields[2]);
				body += fields[2] + "=acc;";
				break;
			case 3:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "acc+=" + fields[2] + ";";
				break;
			case 4:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "acc-=" + fields[2] + ";";
				break;
			case 5:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "acc*=" + fields[2] + ";";
				break;
			case 6:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "acc/=" + fields[2] + ";";
				break;
			case 7:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "if(acc>0)goto " + fields[2] + ";";
				break;
			case 8:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "if(!acc)goto " + fields[2] + ";";
				break;
			case 9:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "if(acc<0)goto " + fields[2] + ";";
				break;
			case 10:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "goto " + fields[2] + ";";
				break;
			case 11:
				if (!fields[0].empty()) body += fields[0] + ":";
				defined.insert(fields[2]);
				body += "scanf(\"%d\",&" + fields[2] + ");";
				break;
			case 12:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "printf(\"%d\\n\"," + fields[2] + ");";
				break;
			case 13:
				defined.insert(fields[0]);
				body += fields[0] + "=" + fields[2] + ";";
				break;
			case 14:
				if (!fields[0].empty()) body += fields[0] + ":";
				body += "return 0;";
				break;
			}
		}
		for (string s : defined)
			code += "int " + s + ";";
		code += body;
	}

	code += "}";

	return code;
}
