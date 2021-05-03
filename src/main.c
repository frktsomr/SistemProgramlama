#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"

int main(int argc, char **argv)
{ 
  JRB b;
  JRB bn;
  IS is;
  char *p;
  char *ptr;
  int counter=0;

if (argc != 2) { fprintf(stderr, "usage: $> kripto -d giriş_metin cikis_metin\n"); exit(1); }

  is = new_inputstruct(".kilit");
  b = make_jrb();

  while (get_line(is) >= 0) 
  { 

     if(is->NF!=2)
        
      continue;  
     p= strdup(is->fields[0]+1);                    
     p[strlen(p)-2] = '\0';
     ptr= strdup(is->fields[1]+1);                    
     ptr[strlen(ptr)-2] = '\0';
  	// printf("%s\n",p);
    (void) jrb_insert_str(b, p, new_jval_s(ptr));
   // free(p);
   // free(ptr);
  }

    jrb_traverse(bn, b) {
    printf("%s\t", bn->key.s);
    printf("%s\n", bn->val.s); 
  }
  // EN SON AĞACI SİLMEYİ UNUTMA.

  return 0;
}