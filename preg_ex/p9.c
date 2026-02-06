#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *adunare(char *s1, char *s2){
  int minte=0;
  char *new=NULL;
  int idx=0;

  int i=0 , j=0;
  
  for(i=strlen(s1)-1,j=strlen(s2)-1 ; i>=0 && j>=0 ; i--,j--){
    int c1=s1[i]-'0';
    int c2=s2[j]-'0';

    int sum=c1+c2+minte;

    new=realloc(new,idx+1);
    new[idx++]=sum%10+'0';
    
    if(sum>=10)
      minte=sum/10;
    else
      minte=0;
  }

  while(i>=0){
    int c1=s1[i]-'0';
    int sum=c1+minte;
    
    new=realloc(new,idx+1);
    new[idx++]=sum%10+'0';
    
    if(sum>=10)
      minte=sum/10;
    else
      minte=0;

    i--;
  }

  while(j>=0){
    int c1=s2[j]-'0';
    int sum=c1+minte;

    
    new=realloc(new,idx+1);
    new[idx++]=sum%10+'0';
    
    if(sum>=10)
      minte=sum/10;
    else
      minte=0;

    j--;
  }

  if(minte){
    new=realloc(new,idx+1);
    new[idx++]=minte+'0';
  }

  for(int i=0 ; i<idx/2 ; i++){
    char aux=new[i];
    new[i]=new[idx-i-1];
    new[idx-i-1]=aux;
  }

  new[idx]=0;
  return new;
}

int main(){
  char *s1=NULL;
  char *s2=NULL;

  size_t size1=0;
  size_t size2=0;

  getline(&s1,&size1,stdin);
  if(s1[strlen(s1)-1]=='\n')
    s1[strlen(s1)-1]=0;
  getline(&s2,&size2,stdin);
  if(s2[strlen(s2)-1]=='\n')
    s2[strlen(s2)-1]=0;


  char *s=adunare(s1,s2);

  printf("%s",s);
  free(s);
  free(s1);
  free(s2);

  return 0;
}
