#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHUNK 10

char *citire(){
  size_t size=CHUNK;
  char *s=malloc(size);
  s[0]=0;

  char aux[CHUNK];

  while(fgets(aux,CHUNK,stdin)){
    if(strlen(aux)+strlen(s)+1>size){
      size+=CHUNK;
      s=realloc(s,size);
    }

    strcat(s,aux);

    if(strchr(aux,'\n')){
      break;
    }
  }

  s[strcspn(s,"\n")]=0;
  s=realloc(s,strlen(s)+1);
  s[strlen(s)]=0;
  

  return s;
}

char *text2hex(const char *s){
  char *res=malloc(strlen(s)*2+2);
  printf("%lu\n",strlen(s));
  res[0]=0;
  for(int i=0 ; i<strlen(s) ; i++){
    char vall[3];
    sprintf(vall,"%x",s[i]);
    strcat(res,vall);
  }
  res[strlen(s)*2]='\0';
  return res;
}

int main(){
  char *p=citire();
  char *s=text2hex(p);
  printf("%s",s);
  free(p);
  free(s);
  return 0;
}
