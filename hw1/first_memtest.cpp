#include <iostream>
#include <stdlib.h>
#include "simpleCharManager.h"
using namespace std;

int main(int argc, char *argv[])
{

  simpleCharManager simplest_mem_manager;

  /*write driver code as described in the assignment to replace this */
  char* c1 = '\0';

  c1 = simplest_mem_manager.alloc_chars(6);
  c1[0] = 'H';
  c1[1] = 'e';
  c1[2] = 'l';
  c1[3] = 'l';
  c1[4] = 'o';
  c1[5] = ' ';
  char* c2 = simplest_mem_manager.alloc_chars(7);
  c2[0] = 'w';
  c2[1] = 'o';
  c2[2] = 'r';
  c2[3] = 'l';
  c2[4] = 'd';
  c2[5] = '!';
  c2[6] = '\n';
  cout << c1;
  char* c3 = simplest_mem_manager.alloc_chars(10);
  c3[0] = 'm';
  c3[1] = 'o';
  c3[2] = 'o';
  c3[3] = 'n';
  c3[4] = '!';
  c3[5] = ' ';
  c3[6] = 'B';
  c3[7] = 'y';
  c3[8] = 'e';
  c3[9] = '\n';
  cout << c3;
}

