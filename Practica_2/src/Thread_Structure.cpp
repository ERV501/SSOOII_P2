#pragma once

#include "../include/Thread_Structure.h"
#include "../include/Result_Structure.h"

#include <definitions.h>
#include <list>

using namespace std;

Thread_Structure::Thread_Structure(int task_begin, int task_end,string task_word,string file_name,int n_thread){
       
        this->task_begin=task_begin;
        this->task_end=task_end;
        this->task_word=task_word;
        this->file_name=file_name;

        this->n_thread = n_thread;

        result_list = list <Result_Structure> ();

}

Thread_Structure::~Thread_Structure(){}

void Thread_Structure::pushResult_list(Result_Structure result_s){
        result_list.push_back(result_s);
}

void Thread_Structure::toString(){
        string str_result_structure;
        while (!result_list.empty())
	{       
		string result_structure_string = ("[Hilo "+to_string(n_thread)+" inicio:"+to_string(task_begin)+" – final: "+to_string(task_end)+"] :: línea "+ to_string(result_list.front().getLine()) +" :: … "+ result_list.front().getWord_previous() +" "+ result_list.front().getWord_objective() +" "+ result_list.front().getWord_next() +" … \r\t");
                printf("%s\n",result_structure_string.c_str());
                result_list.pop_front();
	}
}

int Thread_Structure::getTask_begin(){return task_begin;}
int Thread_Structure::getTask_end(){return task_end;}
string Thread_Structure::getTask_word(){return task_word;}
string Thread_Structure::getFile_name(){return file_name;}

