#include <cstddef>
#include "simpleCharManager.h"



simpleCharManager::simpleCharManager(){
        for(int i = 0; i < BUF_SIZE; i++){
        	(buffer[i] = '\0');
        }
        free_place = buffer;
}

simpleCharManager::~simpleCharManager(){}
             
char* simpleCharManager::alloc_chars(int n){
        char* mem = '\0';
        bool full = false;
        int count = 0;

        if(n > 10000 || n <= 0){
        	return NULL;
        }

        for(int i = 0; i < BUF_SIZE; i++){
        	if((buffer[i] != '\0')){
        		count++;
        	}

        	if(count >= BUF_SIZE){
        		full = true;
        	}
        }

        if(!full){
        	mem = free_place;
        	free_place = free_place + n;
        	return mem;        	
        }

        return NULL;
}

void simpleCharManager::free_chars(char* p){
	int erase = 0;

	for(int i = 0; i < BUF_SIZE; i++){
		if((buffer[i] = *p)){
			erase = i;
			break;
		}
	}

	for(int i = erase; i < BUF_SIZE - erase; i ++){
		(buffer[i] = '\0');
	}

	free_place = p;
}         




