#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char judet[101];
  int beneficiar;
  int suma;
}stat;


stat *stats;
int nrStats;

FILE *fin=NULL;
FILE *fout=NULL;


void eliberare(){
  if (stats) free(stats);
  if (fin) fclose(fin);
  if (fout) fclose(fout);
} 


void adauga(char *linie){
  char *p=strtok(linie,";");
  int idx=0;

  stat aux;

  while(p){
    int ben=0,sum=0;
    
    switch(idx){
    case 0:
      strcpy(aux.judet,p);
      break;
    case 2:
      ben=atoi(p);
      aux.beneficiar=ben;
      break;
    case 4:
      sum=atoi(p);
      aux.suma=sum;
      break;
    default:
      break;
    }

    idx++;
    p=strtok(NULL,";");
  }

  stat *test=realloc(stats,(nrStats+1)*sizeof(stat));
  if(test==NULL){
    printf("nu mai exista memorie");
    eliberare();
    exit(EXIT_FAILURE);
  }

  stats=test;
  stats[nrStats]=aux;
  nrStats++;
  return ;
}

int main(){
  char *linie=malloc(1001);

  if((fin=fopen("indemnizatie.csv","r"))==NULL){
    printf("nu se poate deschide fis de citire");
    exit(EXIT_FAILURE);
  }

  fgets(linie,1000,fin);

  while(fgets(linie,1000,fin)!=NULL){
    adauga(linie);
  }

  for(int i=0 ; i<nrStats ; i++){
    printf("%s %d %d\n",stats[i].judet,stats[i].beneficiar,stats[i].suma);
  }

  free(linie);
  eliberare();
}
