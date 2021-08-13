#include <iostream>
#include <string>
#include "controller.h"

using std::cin;
using std::getline;

// main function where argc is the number of command line arguments, argv is the arguments
int main(int argc, char **argv) {
	int seed;
	bool setseed = false;
    int startingLevel;
	bool graphics = true;
	std::string f1 = "", f2 = "";

    Biquadris game;
    
	// we loop through the arguments
	int i = 1;
	while(i<argc){
		// get the next flag
		std::string flag = argv[i];
		// if it is the -c flag we need to get the indices
		if(!flag.compare("-text")) {
			game.graphics = false;
		}
		// if its the -d flag
		else if (!flag.compare("-seed")) {
			// set the d (and f) flag to true as d and f must be used together
            seed = std::stoi(argv[i+1]);
			setseed = true;
			game.seed = seed;
			srand(seed);
			++i;
		}
		else if (!flag.compare("-scriptfile1")){
			f1 = argv[i+1];
			game.f1 = f1;
			++i;
		}
		else if (!flag.compare("-scriptfile2")){
			f2 = argv[i+1];
			game.f2 = f2;
			++i;
		}
		// if it is the d flag
		else if(!flag.compare("-startlevel")) {
            startingLevel = std::stoi(argv[i+1]);
            game.g1.level = startingLevel;
            game.g2.level = startingLevel;
			++i;
		}
		// // else it must be the input and/or output file paths
		// else {
		// 	game.run();
		// 	break;
		// }
		++i;
	}
	if (f1 == ""){
		f1 = "sequence1.txt";
		game.f1 = f1;
	}
	if (f2 == ""){
		f2 = "sequence2.txt";
		game.f2 = f2;
	}
	if(!setseed){
		srand(time(0));
	}
    game.run();
}