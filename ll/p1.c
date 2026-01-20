#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CHUNK 10

FILE *fin;
FILE *fout;

char **cuvinte;
int nrCuv=0;

char *citire(char *filepath){
  size_t size=CHUNK;

  if((fin=fopen(filepath,"rt"))==NULL){
    printf("eroare");
    exit(1);
  }
  
  char *s=malloc(CHUNK);
  char aux[CHUNK];

  s[0]=0;

  while((fgets(aux,CHUNK,fin))){
    size_t newline_idx = strcspn(aux, "\n");
    if (aux[newline_idx] == '\n') {
      aux[newline_idx] = ' ';
    }

    if(strlen(aux)==0)
      continue;

    if(strlen(aux)+strlen(s)+1>size){
      size+=CHUNK;
      s=realloc(s,size);
    }

    strcat(s,aux);
  }

  s=realloc(s,strlen(s)+1);

  if((fclose(fin))!=0){
    printf("erorae");
    exit(1);
  }

  return s;
}


char *citireCuLinie(char *filepath){
  char *s=malloc(CHUNK);
  size_t size=CHUNK;

  s[0]=0;

  char aux[CHUNK];

  if((fin=fopen(filepath,"rt"))==NULL){
    printf("eroare");
    exit(1);
  }

  while((fgets(aux,CHUNK,fin))){
    if(strlen(s) + strlen(aux) + 1>size){
      size+=CHUNK;
      s=realloc(s,size);
    }

    strcat(s,aux);
  }

  s=realloc(s,strlen(s)+1);

  if((fclose(fin))!=0){
    printf("erorae");
    exit(1);
  }
  
  return s;
}

void citireCuv(){
  char *cuvs=citire("cuvinte.txt");

  char *p=strtok(cuvs," ");

  while(p){
    char *cuvant=malloc(strlen(p)+1);
    strcpy(cuvant,p);
    cuvinte=realloc(cuvinte,(nrCuv+1)*sizeof(char *));
    cuvinte[nrCuv]=cuvant;
    nrCuv++;

    p=strtok(NULL, " ");
  }

  free(cuvs);

  return;
}

int idxCuv;

char *verif(char *text) {
  char *min_p = NULL;
    
  idxCuv = -1; 

  for(int i = 0; i < nrCuv; i++) {
    char *p = strstr(text, cuvinte[i]);

    if (p != NULL) {
      if (min_p == NULL || p < min_p) {
	min_p = p;
	idxCuv = i;
      }
    }
  }

  return min_p;
}

char *transform(int idx){
  char *cuv=malloc(strlen(cuvinte[idx])+1);
  cuv[0]=cuvinte[idx][0];
  for(int i=1 ; i<strlen(cuvinte[idx])-1 ; i++){
    cuv[i]='*';
  }
  cuv[strlen(cuvinte[idx])-1]=cuvinte[idx][strlen(cuvinte[idx])-1];
  cuv[strlen(cuvinte[idx])]=0;

  return cuv;
}

void replace(char *s){
  
  char *new = malloc(strlen(s)+1);
  new[0]=0;

  char *s_ptr=s;
  char *new_ptr=new;

  char *gs=NULL;


  while((gs=verif(s_ptr))){
    int sect_len=strlen(s_ptr)-strlen(gs);
    
    strncpy(new_ptr,s_ptr,sect_len);
    new_ptr[sect_len]=0;
    new_ptr+=sect_len;
    s_ptr+=sect_len;

    char *cuv=transform(idxCuv);
    printf("%s",cuv);
    
    strcat(new_ptr,cuv);

    s_ptr+=strlen(cuv);
    new_ptr+=strlen(cuv);

    free(cuv);
  }

  int sect_len=strlen(s_ptr);
  strncpy(new_ptr,s_ptr,sect_len);

  new[strlen(s)]=0;
  
  if((fout=fopen("res.txt","wt"))==NULL){
    printf("eroare");
    exit(1);
  }

  fprintf(fout,"%s",new);

  free(new);

  fclose(fout);
  return;
}


int main(){
  citireCuv();

  char *text = citireCuLinie("text.txt");

  replace(text);

  for(int i=0 ; i<nrCuv ; i++){
    free(cuvinte[i]);
  }

  free(cuvinte);
  free(text);
}
