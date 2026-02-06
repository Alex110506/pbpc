#include <stdio.h>
#include <stdint.h>

int nrseg(uint32_t n){
  int seg=1;
  int prev=n&1;
  for(int i=0 ; i<32 ; i++){
    if((n&1) != prev){
      seg++;
    }

    prev=n&1;
    n>>=1;
  }

  return seg;
}

int main(){
  uint32_t n=4;
  printf("%d",nrseg(n));
}
