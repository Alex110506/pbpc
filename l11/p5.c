#include <stdio.h>
#include <stdlib.h>

int main(){
  int capa=0;
  int *num=NULL;

  int n=0;

  int x=0;
  
  while(scanf("%d",&x)==1){
    if(x==0)
      break;
    
    capa+=sizeof(int);
    num=realloc(num,capa);

    *(num+n)=x;
    n++;
  }

  for(int i=0 ; i<n ; i++){
    printf("%d ",num[i]);
  }

  free(num);
  return 0;
}
