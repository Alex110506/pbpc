#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int verif(char *s1, char *s2){
  int l1=strlen(s1);
  int l2=strlen(s2);

  if(l1<2 || l2<2)
    return 0;

  if(tolower(s1[l1-2])==tolower(s2[0]) && tolower(s1[l1-1])==tolower(s2[1]))
    return 1;

  return 0;
}

int main(){
  char s[101];
  char *res=NULL;

  if(scanf("%s",s)==1){
    res=malloc((strlen(s)+1)*sizeof(char));
    strcpy(res,s);
  }else{
    return 0;
  }

  while(scanf("%s",s)==1){
    if(verif(res,s)){
      size_t size=strlen(s)+strlen(res)+2;
      res=realloc(res,size);
      strcat(res,"-");
      strcat(res,s);
    }
  }

  printf("%s\n",res);
  free(res);
}
