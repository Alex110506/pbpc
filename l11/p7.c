#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 10

char *citire(){
  size_t size=CHUNK;

  char *s=malloc(size);
  char aux[CHUNK];
  s[0]=0;

  while((fgets(aux,CHUNK,stdin))){
    aux[strcspn(aux,"\n")]=0;
    if(strlen(aux)==0)
      continue;
    
    if(strlen(s)+strlen(aux)+1>size){
      size+=CHUNK;
      s=realloc(s,size);
    }

    strcat(s,aux);

  }



  return s;
}

char *hex2text(const char *hexs){
  size_t len = strlen(hexs)/2+1;
  
  char *s=malloc(len);

  const char *ptr_hexs=hexs;

  for(int i=0 ; i<len-1 ; i++){
    char hexy[3];
    strncpy(hexy,ptr_hexs,2);
    hexy[2]=0;
    char c=(char)strtol(hexy,NULL,16);
    ptr_hexs+=2;
    *(s+i)=c;
  }
  s[len-1]=0;
  return s;
}

int main(){
  char *p=citire();
  char *s=hex2text(p);

  printf("%s",s);
  free(p);
  free(s);
  return 0;
}
