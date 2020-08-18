#include "app/Application.h"

#include <iostream>
#include <string>
#include <complex>

using namespace std;


constexpr char USAGE[] {"Usage: ./calc [mode]\nmode:\n\t-d for decimals (default)\n\t-f for floats\n\t-c for complex"};


int main(int argc, char * argv[]) {
	string type {"-d"};

	if (argc == 2) {
		type = argv[1];
		if (type != "-d" && type != "-f") {
			cerr << USAGE << endl;
			return 1;
		}
	}

	if (type == "-d") {
		Application<int> app;
		app.start();
	}
	else if (type == "-f") {
		Application<double> app;
		app.start();
	}

	return 0;
}
