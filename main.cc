#include <iostream>
#include <string>
#include "controller.h"

using std::cin;
using std::getline;

// main function where argc is the number of command line arguments, argv is the arguments
int main(int argc, char **argv) {
	int seed;
    int startingLevel;

    Biquadris game;
    
	// we loop through the arguments
	for(int i = 1; i < argc; i++) {
		// get the next flag
		std::string flag = argv[i];
		// if it is the -c flag we need to get the indices
		if(!flag.compare("text")) {
			game.g1.noGraphics = false;
            game.g2.noGraphics = false;
		}
		// if its the -d flag
		else if (!flag.compare("seed")) {
			// set the d (and f) flag to true as d and f must be used together
            cin >> seed;
			srand(seed);
		}
		// if it is the d flag
		else if(!flag.compare("startlevel")) {
            cin >> startingLevel;
            game.g1.level = startingLevel;
            game.g2.level = startingLevel;
		}
		// // else it must be the input and/or output file paths
		// else {
		// 	game.run();
		// 	break;
		// }
	}
    game.run();
}