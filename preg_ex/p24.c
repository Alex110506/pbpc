#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv){

  srand(time(NULL));
  int n=rand();
  printf("%d",n);
}
