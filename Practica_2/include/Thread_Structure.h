#pragma once

#include "../include/Result_Structure.h"

#include "../include/definitions.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <list>
#include <string>

using namespace std;

class Thread_Structure{

private:
    int task_begin;
    int task_end;
    int n_thread;
    string task_word;
    string file_name;
    list <Result_Structure> result_list;

public:
    Thread_Structure(int task_begin, int task_end,string task_word,string file_name,int n_thread);
    ~Thread_Structure();
    int getTask_begin();
    int getTask_end();
    string getTask_word();
    string getFile_name();
    void pushResult_list(Result_Structure result_s);
    void toString();

};