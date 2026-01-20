#include <stdio.h>
#include <stdlib.h>

FILE *fout;

int main(){
  int x=0;
  int *lista=NULL;
  int n=0;
  
  while(scanf("%d",&x)==1 && x!=0){
    lista=realloc(lista,(n+1)*sizeof(int));
    lista[n]=x;
    n++;
  }

  for(int i=0 ; i<n ; i++){
    for(int j=i+1 ; j<n ; j++){
      if(lista[i]>lista[j]){
	int aux=lista[i];
	lista[i]=lista[j];
	lista[j]=aux;
      }
    }
  }

  if((fout=fopen("out.txt","wt"))==NULL){
    printf("fisierul de iesire nu a putut fi deschis");
    exit(EXIT_FAILURE);
  }

  for(int i=0 ; i<n ; i++){
    fprintf(fout,"%d|",lista[i]);
  }
  return 0;
}
