#include <stdio.h>
#include <stdlib.h>

FILE *fin=NULL;
FILE *fout=NULL;

void eliberare(){
  if(fin) fclose(fin);
  if(fout) fclose(fout);
  return ;
}

int main(){
  int nr=0;

  if((fin=fopen("integers.bin","r"))==NULL){
    printf("nu se poate deschide citirea");
    exit(EXIT_FAILURE);
  }

  if((fout=fopen("ex1.txt","wt"))==NULL){
    printf("nu se poate deschide scrierea");
    exit(EXIT_FAILURE);
  }
  
  while(fread(&nr, sizeof(int), 1, fin) == 1){
    fprintf(fout,"%08x ",nr);
  }

  eliberare();
  return 0;
}
