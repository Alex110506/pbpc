#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

char *binar(uint16_t nr){
  uint16_t mask=1<<15;

  char *s=malloc(17);
  for(int i=0 ; i<16 ; i++){
    if(nr & mask){
      s[i]='1';
    }else{
      s[i]='0';
    }

    mask>>=1;
  }
  s[16]=0;
  return s;
}

char *arraytostr(uint16_t *array, int size){
  char *s=malloc(17*size+1);
  s[0]=0;

  for(int i=0 ; i<size ; i++){
    char *snr=binar(array[i]);
    strcat(s,snr);
    strcat(s," ");

    free(snr);
  }

  return s;
}

int main(){
  uint16_t array[]={12,200,123,1,700};
  int size=5;

  char *s=arraytostr(array,size);
  printf("%s",s);

  free(s);
  return 0;
}
