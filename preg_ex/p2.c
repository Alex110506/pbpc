#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define CHUNK 10

char *citire(){
  char *s=malloc(CHUNK);
  size_t size=CHUNK;

  s[0]=0;

  char aux[CHUNK];

  while(fgets(aux,CHUNK,stdin)){
    if(strlen(s)+strlen(aux)+1 >= size){
      size+=CHUNK;
      s=realloc(s,size);
    }

    char *p=strchr(aux,'.');
    if(p){
      aux[strlen(aux)-strlen(p)+1]=0;
      strcat(s,aux);
      break;
    }

    strcat(s,aux);
  }

  s=realloc(s,strlen(s)+1);
  return s;
}

void transform(char *s){
  int size=strlen(s)+1;
  char *new=malloc(size);
  int idx=0;
  
  for(int i=0 ; i<strlen(s) ; i++){
    if((i==0 && isdigit(s[i])) || (isdigit(s[i]) && !isdigit(s[i-1]))){
      size++;
      new=realloc(new,size);

      new[idx++]='$';
      new[idx++]=s[i];
    }else{
      new[idx++]=s[i];
    }
  }

  new[idx]=0;

  printf("%s",new);
  free(new);

  
}

int main(){
  char *prop=citire();

  transform(prop);
  
  free(prop);
  return 0;
}
