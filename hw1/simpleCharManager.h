#ifndef SIMPLECHARMANAGER_H
#define SIMPLECHARMANAGER_H




/**
* Simplest Character Storage Manager
*/
class simpleCharManager
{
	public:
		simpleCharManager();
		~simpleCharManager();

		char* alloc_chars(int n);
		void free_chars(char* p);          

	protected:
		static const int BUF_SIZE = 10000;
		char buffer[BUF_SIZE];
		char* free_place;
};





#endif
