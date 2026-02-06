#include <stdio.h>
#include <stdint.h>

void printBin(uint32_t nr){
  uint32_t mask=1<<31;
  for(int i=0 ; i<32 ; i++){
    if(mask & nr)
      printf("1");
    else
      printf("0");

    mask>>=1;
  }

  return;
}

int main(){
  uint32_t nr=0;
  uint8_t idx=0;

  if(scanf("%u %hhu",&nr,&idx)!=2){
    printf("eroare citire");
    return 0;
  }
  
  uint32_t bs=nr & 1<<(idx+1);
  uint32_t bd=nr & 1<<(idx-1);

  if(bs && bd){
    nr= nr | (1<<(idx));
  }else{
    if(!bs && !bd){
      nr=nr & (~(1<<idx));
    }
  }

  printBin(nr);  
}
