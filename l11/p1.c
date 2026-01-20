#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHUNK 10

char *citire() {
  int capacitate = CHUNK;
  char *s = malloc(capacitate * sizeof(char));
    
  if (s == NULL) return NULL;

  s[0] = '\0'; 

  char aux[CHUNK]; 

  while (fgets(aux, CHUNK, stdin)) {
    if (strlen(s) + strlen(aux) + 1 > capacitate) {
      capacitate += CHUNK;
            
      s = realloc(s, capacitate);
    }

    strcat(s, aux);
    
    if (strchr(aux, '\n')) {
      break;
    }
  }
  s = realloc(s, strlen(s) + 1);

  return s;
}

int main() {
  char *p = NULL;
    
  printf("Scrie un text lung: ");
  p = citire();
    
  if (p != NULL) {
    printf("Text citit: %s", p);
    printf("Adresa pointer: %p | Lungime text: %lu\n", (void*)p, strlen(p));
        
    free(p);
  }
    
  return 0;
}
