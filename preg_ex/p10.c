#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char ro[101];
  char en[101];
}Cuvant;

Cuvant *dict;
int size;

void citire(){
  char aux[101];
  int idx;
  
  while(fgets(aux,100,stdin)){
    char *eng=strtok(aux,"=");
    char *ro=strtok(NULL,".");

    dict=realloc(dict,sizeof(Cuvant)*(idx+1));
    strcpy(dict[idx].ro,ro);
    strcpy(dict[idx].en,eng);

    idx++;

    while(ro){
      ro=strtok(NULL,".");
    }

    //free(eng);
    //free(ro);
  }

  size=idx;
  return;
}

void afis(){
  for(int i=0 ; i<size ; i++){
    printf("%s %s \n",dict[i].ro,dict[i].en);
  }
}

int main(){
  citire();
  afis();

  free(dict);
  return 0;
}
