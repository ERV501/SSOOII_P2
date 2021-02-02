#pragma once

#include "../include/definitions.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <string>

using namespace std;

class Result_Structure{

    private:
        int line;
        string word_previous;
        string word_next;
        string word_objective;

    public:
        Result_Structure(string word_previous,string word_next,string word_objective,int line);
        ~Result_Structure();
        /*string toString();*/
        int getLine();
        string getWord_previous();
        string getWord_next();
        string getWord_objective();
};
