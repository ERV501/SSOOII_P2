
#include "../include/SSOOIIGLE.h"
#include "../include/Organizer.h"
#include "../include/Thread_Structure.h"
#include "../include/Result_Structure.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <string>
#include <vector>

mutex mtx;

int main(int argc, char const *argv[])
{

    string file_name, task_word;
    int thread_number;

    checkArgs(argc,argv,file_name,task_word,thread_number);

    vector <thread> vector_of_threads = vector<thread>();
	vector <Thread_Structure> vector_of_threads_structure = vector <Thread_Structure>();

    threadCreation(file_name,thread_number,vector_of_threads_structure,task_word);
    
    threadLaunch(thread_number,vector_of_threads,vector_of_threads_structure);

    threadFinalization(vector_of_threads);

    printResults(vector_of_threads_structure);
    
    return EXIT_SUCCESS;
}

void checkArgs(int argc, char const *argv[], string &file_name, string &task_word, int &thread_number){

    if(argc != 4){
        printf("--[Error in argment number] Execution: SSOOIIGLE <file_name> <word> <thread_number>--\n");
        exit(EXIT_FAILURE);
    }

    file_name = argv[1];
    task_word = argv[2];
    thread_number = atoi(argv[3]);

}

void threadCreation(string file_name,int thread_number,vector <Thread_Structure> &vector_of_threads_structure,string task_word){

    int line_number = countLines(file_name);
    int task_begin = 0, task_end = 0, section = 0;
    int concurent_threads_supported = std::thread::hardware_concurrency();

    if (thread_number > (concurent_threads_supported))
    {
        printf("--[Number of threads unsupported (max = %d)] Please, decrease the number of threads--\n",concurent_threads_supported);
        exit(EXIT_FAILURE);

    }else if (thread_number <= 0){
        printf("--[Number of threads unsupported (min = 1)] Please, increase the number of threads--\n");
        exit(EXIT_FAILURE);

    }else
    {
        section = line_number/thread_number;
        int i = 0;
        task_end = section -1;

        for (i = 0; i < thread_number-1; i++){
            vector_of_threads_structure.emplace_back(task_begin,task_end,task_word,file_name,(i+1));
            task_begin = task_begin + section;
            task_end = task_begin + section - 1;

        }

        task_end = line_number - 1;

        vector_of_threads_structure.emplace_back(task_begin,task_end,task_word,file_name,(i+1));
            

    }
    
}

int countLines(string file_name){
 
 int line_number = 0;
 string line;
 ifstream file(file_name);

    if(file.is_open())
    {
        while(!file.eof())
    {
            getline(file,line);
            line_number++;
        }
        file.close();
    }

    if(line_number == 0){
        printf("--[File is empty] Please, choose a non empty text file--\n");
        exit(EXIT_FAILURE);
    }
    
    
return line_number;
}

void threadLaunch(int thread_number,vector <thread> &vector_of_threads,vector <Thread_Structure> &vector_of_threads_structure){
    for (int i = 0; i < thread_number; i++){
		vector_of_threads.push_back(thread(Organizer(&vector_of_threads_structure[i], &mtx)));
	}
}

void threadFinalization(vector <thread> &vector_of_threads){
    for (unsigned int i = 0; i < vector_of_threads.size(); i++){
		if (vector_of_threads.at(i).joinable()){
			vector_of_threads.at(i).join();
		}
	}
}

void printResults(vector <Thread_Structure> &vector_of_threads_structure){
    for (unsigned int i = 0; i < vector_of_threads_structure.size(); i++){
		vector_of_threads_structure.at(i).toString();
	}
}

