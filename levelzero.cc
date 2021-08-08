#include <iostream>
#include <vector>
#include <string>
#include "levelzero.h"
#include "block.h"

LevelZero::LevelZero(std::string s1, std::string s2){
	if (s1 != "") seq1 = new std::ifstream{s1};
	if (!*seq1) std::cerr<<"Failed sequence1 txt to ifstream"<<std::endl;
	if (s2 != "") seq2 = new std::ifstream{s2};
	if (!*seq2) std::cerr<<"Failed sequence2 txt to ifstream"<<std::endl;
}
LevelZero::~LevelZero(){
	delete seq1;
	delete seq2;
}
int LevelZero::getLevel(){return 0;}
bool LevelZero::getHeavy(){return false;}
Block LevelZero::getNextBlock();
Block LevelZero::genNext(int s){
	std::string newBlock;
	std::istream *seq;
	if (s == 1) seq = seq1;
	else seq = seq2;
	
	seq->exceptions(std::ios::eofbit|std::ios::failbit);
	while (true){
		try{
			*seq >> newBlock; //if eof, should throw exception before we increment i...

			if (newBlock == "I"){
				IBlock theBlock;
				return theBlock;
			}
			if (newBlock == "J"){
                                JBlock theBlock;
                                return theBlock;
                        }
			if (newBlock == "L"){
                                LBlock theBlock;
                                return theBlock;
                        }
			if (newBlock == "O"){
                                OBlock theBlock;
                                return theBlock;
                        }
			if (newBlock == "S"){
                                SBlock theBlock;
                                return theBlock;
                        }
			if (newBlock == "Z"){
                                ZBlock theBlock;
                                return theBlock;
                        }
			if (newBlock == "T"){
                                TBlock theBlock;
                                return theBlock;
                        }

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
	Block fake;
	return fake; //theoretically this should never happen...
		     //should probs make exception to throw if we reach end without anything to return
}




