#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *tran(char *s){
  char *new=NULL;
  int size=0;

  for(int i=0 ; i<strlen(s) ; i++){
    if(isdigit(s[i])){
      int cnt=0;
      int j=i;
      while(isdigit(s[j])){
	cnt++;
	j++;
      }

      char aux[20];
      strncpy(aux,s+i,cnt);
      aux[cnt]=0;
      int nr=atoi(aux);
      char hex[20];
      sprintf(hex,"%x",nr);

      printf("%d\n",cnt);

      new=realloc(new,size+strlen(hex)+1);
      new[size]=0;
      size+=strlen(hex);
      strcat(new,hex);

      i=j-1;
    }else{
      new=realloc(new,size+1);
      new[size]=s[i];
      size+=1;
    }
  }
  new[size]=0;
  return new;
}

int main(){
  char *s="Ana are 22 de mere, dar 6 pere";
  char *s1=tran(s);

  printf("%s",s1);
  free(s1);
}
