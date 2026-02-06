#include <stdio.h>
#include <string.h>

enum en{
  var1,var2
};

union pula{
  int a;
  long long int b;
};

struct caca{
  char aux[10];
  int n;
  long long int p;
  enum en tip;
  union pula c;
};

int main(){/*
  char aux[100]="pula in pizda";

  FILE *fout =fopen("mena.bin","wb");
  FILE *fin =fopen("mena.bin","rb");
  
  fwrite(aux,1,14,fout);

  fclose(fout);

  char auxxx[100];
  fread(auxxx,1,14,fin);

  fclose(fin);

  printf("%s",auxxx);*/

  FILE *fout =fopen("mena.bin","wb");
  FILE *fin =fopen("mena.bin","rb");

  struct caca a;
  strcpy(a.aux,"penis");
  a.n=2;
  a.p=10000;
  a.tip=1;
  a.c.a=210;

  fwrite(&a,sizeof(struct caca),1,fout);
  fclose(fout);

  struct caca penismare;
  
  fread(&penismare,sizeof(struct caca),1,fin);


  printf("%s %d",penismare.aux,penismare.c.a);
}
