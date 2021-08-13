#include <iostream>
#include <vector>
#include <string>
#include "levelzero.h"
#include "block.h"
#include "iblock.h"

LevelZero::LevelZero(std::string s1, std::string s2){
	if (s1 != "") seq1 = std::make_shared<std::ifstream>(s1);
	else{
		seq1 = std::make_shared<std::ifstream>("sequence1.txt");
	}
	if (!*seq1) std::cerr<<"Failed sequence1 txt to ifstream"<<std::endl;

	if (s2 != "") seq2 = std::make_shared<std::ifstream>(s2);
	else
	{
		seq2 = std::make_shared<std::ifstream>("sequence2.txt");
	}
	if (!*seq2) std::cerr<<"Failed sequence2 txt to ifstream"<<std::endl;
}

LevelZero::~LevelZero(){}

int LevelZero::getLevel(){return 0;}
bool LevelZero::getHeavy(){return false;}
//Block LevelZero::getNextBlock();
char LevelZero::genNext(int s){
	std::string newBlock;
	std::shared_ptr<std::istream> seq;
	if (s == 1) seq = seq1;
	else seq = seq2;
	char nextBlock = 'e';
	seq->exceptions(std::ios::eofbit|std::ios::failbit);
	while (true){
		try{
			*seq >> newBlock; //if eof, should throw exception before we increment i...

			if (newBlock == "I"){
				nextBlock = 'i';
			}
			else if (newBlock == "J"){
                nextBlock = 'j';
            }
			else if (newBlock == "L"){
                nextBlock = 'l';
            }
			else if (newBlock == "O"){
                nextBlock = 'o';
            }
			else if (newBlock == "S"){
                nextBlock = 's';
            }
			else if (newBlock == "Z"){
                nextBlock = 'z';
            }
			else if (newBlock == "T"){
                nextBlock = 't';
            }
			return nextBlock;
		}
		catch(std::ios_base::failure&){
			if (seq->eof()){
				seq->clear();
				seq->seekg(0, seq->beg);
				continue;
			}
			else std::cerr<<"Bad read from sequence"<<std::endl;
		}
	}
	return nextBlock; 
	// theoretically this should never happen...
	// should probs make exception to throw if we reach end without anything to return
	// it returns 'e' for empty
}




