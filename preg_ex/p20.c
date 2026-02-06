#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_replace(char *where, char *what, char *replace){
  char *new=NULL;
  char *p=NULL;

  int size=0;

  
  while((p=strstr(where,what))){
    //new=realloc(new,strlen(new)+strlen(replace)+1);
    
    int len=strlen(where)-strlen(p);

    int sz=size;
    size+=len+strlen(replace);
    new=realloc(new,size+1);
    
    strncpy(new+sz,where,len);
    new[sz+len]=0;
    where+=len;
    strcat(new,replace);
    where+=strlen(what);
  }

  new=realloc(new,size+strlen(where)+1);
  strcat(new,where);

  return new;
}

int main(){
  char s[]="Acesta este un string si un string se termina in 0x00";

  char *s1=string_replace(s,"string","penis mare");

  printf("%s",s1);

  //free(s1);
}
