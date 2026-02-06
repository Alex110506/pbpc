#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define CHUNK 10

char *citire(){
  char *s =malloc(CHUNK);
  int size=CHUNK;

  char aux[CHUNK];

  s[0]=0;

  while(fgets(aux,CHUNK,stdin)){
    if(strlen(s)+strlen(aux)+1>size){
      size+=CHUNK;
      s=realloc(s,size);
    }

    strcat(s,aux);
  }

  s=realloc(s,strlen(s)+1);

  return s;
}

void functie(char *s){
  char *new=NULL;
  int size=0;

  for(int i=0 ; i<strlen(s) ; i++){
    if(i>0 && !isalpha(s[i]) && !isalpha(s[i-1])){
      continue;
    }else{
      new=realloc(new,size+1);
      new[size]=s[i];
      size++;
    }
  }

  printf("%s",new);
  free(new);

  return ;
}

int main(){
  char *s=citire();

  functie(s);
  
  free(s);
}
