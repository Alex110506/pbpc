#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *string_replace_dynamic(const char *where, const char *what, const char *replace) {
  int len_what = strlen(what);
  int len_replace = strlen(replace);
    
  int count = 0;
  const char *temp = where;
  while((temp = strstr(temp, what))) {
    count++;
    temp += len_what;
  }

  size_t new_len = strlen(where) + count * (len_replace - len_what) + 1;
  char *result = malloc(new_len);
  if (!result) return NULL;

  char *ptr_dest = result;
  const char *ptr_src = where;
  const char *found;

  while ((found = strstr(ptr_src, what))) {
    int len_segment = found - ptr_src;

    strncpy(ptr_dest, ptr_src, len_segment);
        
    ptr_dest += len_segment;

    strcpy(ptr_dest, replace);

    ptr_dest += len_replace;

    ptr_src = found + len_what;
  }

  strcpy(ptr_dest, ptr_src);

  return result;
}


int main(){
  char s1[] = "Acesta este un string si un string este terminat cu 0x00";
  char s2[] = "string";
  char s3[] = "sir de caractere";
  char *p=string_replace_dynamic(s1, s2, s3);
  printf("%s",p);
}
