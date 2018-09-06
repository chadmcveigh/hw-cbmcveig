#include "flexCharManager.h"

flexCharManager::flexCharManager(){
	used_mem_size = 2;

	used_memory = new Mem_Block*[used_mem_size];

	free_mem = BUF_SIZE;

	active_requests = 0;

}

flexCharManager::~flexCharManager(){
	delete [] used_memory;
}
             
char* flexCharManager::alloc_chars(int n){
	Mem_Block* mem = new Mem_Block;

	int blank_spots = 0;
	int free_index = 0;

	bool insert = false;

	mem->size = n;

	if(active_requests == used_mem_size){
		Mem_Block** temp = new Mem_Block*[used_mem_size * 2];

		for(int i = 0; i < used_mem_size; i++){
			temp[i] = used_memory[i];
		}

		for(int i = 0; i < used_mem_size; i++){
			delete used_memory[i];
		}

		delete [] used_memory;

		used_mem_size = used_mem_size * 2;

		used_memory = new Mem_Block*[used_mem_size];

		for(int i = 0; i < used_mem_size; i++){
			used_memory[i] = temp[i];
		}

		delete [] temp;
	}

	for(int i = 0; i < BUF_SIZE; i++){
		if((buffer[i] == '\0')){
			free_index = i;

			for(int j = i; j < n + i; j++){
				if((buffer[j] == '\0')){
					blank_spots++;
				}
				else{
					free_index = 0;
					break;
				}

				if(blank_spots == n){
					mem->physical_location = &buffer[free_index];
					free_mem = free_mem - n;
					insert = true;
					break;
				}
			}
			if(insert){
				break;
			}
		}
	}

	if(insert){
		used_memory[active_requests] = mem;
		active_requests++;
		return mem->physical_location;
	}

       return NULL;
}

void flexCharManager::free_chars(char* p){
	int valid_index = 0;

	for(int i = 0; i < BUF_SIZE; i++){
		if(&buffer[i] == p){
			valid_index = i;
			break;
		}
	}

	for(int i = 0; i < used_mem_size; i++){
		if(used_memory[i]->physical_location == p){
			for(int j = valid_index; j < used_memory[i]->size + valid_index; j++){
				buffer[j] = '\0';
				free_mem = free_mem - used_memory[i]->size;
			}
		}
	}

	for(int i = 0; i < used_mem_size; i++){
		if(used_memory[i]->physical_location == p){
			used_memory[i] = '\0';
			active_requests--;
		}
	}

	if(used_mem_size >= active_requests * 4){
		Mem_Block** temp = new Mem_Block*[used_mem_size/2];

		for(int i = 0; i < used_mem_size; i++){
			if(used_memory[i] != '\0'){
				temp[i] = used_memory[i];
			}
		}

		for(int i = 0; i < used_mem_size; i++){
			delete [] used_memory[i];
		}

		delete used_memory;

		used_mem_size = used_mem_size/2;

		used_memory = new Mem_Block*[used_mem_size];

		for(int i = 0; i < used_mem_size; i++){
			used_memory[i] = temp[i];
		}

		delete [] temp;

	}
}         


