#pragma once

#include "../include/Thread_Structure.h"
#include "../include/Result_Structure.h"
#include "../include/Organizer.h"

#include "../include/definitions.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <string>

using namespace std;

void checkArgs(int argc, char const *argv[], string &file_name, string &task_word, int &thread_number);
int countLines(string file_name);

void threadCreation(string file_name,int thread_number,vector<Thread_Structure> &vector_of_threads_structure,string task_word);
void threadLaunch(int thread_number,vector<thread>&vector_of_threads,vector<Thread_Structure>&vector_of_threads_structure);
void threadFinalization(vector<thread>&vector_of_threads);

void printResults(vector<Thread_Structure>&vector_of_threads_structure);