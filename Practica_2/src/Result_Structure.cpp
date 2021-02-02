#pragma once

#include "../include/Result_Structure.h"

#include <definitions.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <string>

using namespace std;

Result_Structure::Result_Structure(string word_previous,string word_next,string word_objective,int line){
          
	this->word_previous = word_previous;
	this->word_next = word_next;
        this->word_objective = word_objective;
        
        this->line = line;

}

Result_Structure::~Result_Structure(){}

string Result_Structure::getWord_previous(){return word_previous;}
string Result_Structure::getWord_next(){return word_next;}
string Result_Structure::getWord_objective(){return word_objective;}
int Result_Structure::getLine(){return line;}
