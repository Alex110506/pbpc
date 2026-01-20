#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 100

char **linii;
int nrLinii=0;

FILE *fin=NULL;
FILE *fout=NULL;

void eliberare(){
  for(int i=0 ; i<nrLinii ; i++){
    free(linii[i]);
  }
  free(linii);
  if(fin) fclose(fin);
  if(fout) fclose(fout);
  return ;
}

char *citire(){
  int size=CHUNK;
  char *s=malloc(size*sizeof(char));
  if(s==NULL){
    printf("Nu e destula memorie");
    eliberare();
    exit(EXIT_FAILURE);
  }

  s[0]='\0';

  char aux[CHUNK];
  int citit=0;

  while(fgets(aux,CHUNK,fin)!=NULL){
    citit=1;
    if(strlen(s)+strlen(aux)+1>size){
      size+=CHUNK;
      s=realloc(s,size);
    }

    strcat(s,aux);

    if(strchr(aux,'\n')){
      break;
    }
  }
  if(!citit){
    free(s);
    return NULL;
  }

  s=realloc(s,strlen(s)+1);

  return s;
}


void write_sort(char **lines,char *filepath){
  if((fout=fopen(filepath,"wt"))==NULL){
    printf("Nu se paote descide fis de scr");
    exit(1);
  }

  for(int i=0 ; i<nrLinii ; i++){
    for(int j=i+1 ; j<nrLinii ; j++){
      if(strcmp(linii[i],linii[j])>0){
	char *aux=malloc((strlen(linii[i])+1) * sizeof(char));
	strcpy(aux,linii[i]);
	linii[i]=realloc(linii[i],(strlen(linii[j])+1)*sizeof(char));
	strcpy(linii[i],linii[j]);
	linii[j]=realloc(linii[j],(strlen(aux)+1)*sizeof(char));
	strcpy(linii[j],aux);
	free(aux);
      }
    }
  }

  for(int i=0 ; i<nrLinii ; i++){
    fprintf(fout,"%s",linii[i]);
  }
  return ;
}


int main(){
  char *linie=NULL;

  if((fin=fopen("scrisoare.txt","r"))==NULL){
    printf("nu se poate deschide fis de citire");
    exit(EXIT_FAILURE);
  }

  while((linie=citire())){
    char **aux=realloc(linii,(nrLinii+1)*sizeof(char*));
    if(aux==NULL){
      printf("mem insuficienta");
      exit(1);
    }

    linii=aux;
    linii[nrLinii]=linie;
    nrLinii++;
  }

  for(int i=0 ; i<nrLinii ; i++){
    printf("%s",linii[i]);
  }

  write_sort(linii,"ex4.txt");

  eliberare();
}
