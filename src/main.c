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

if (argc != 2) { fprintf(stderr, "usage: $> kripto -d giriş_metin cikis_metin\n"); exit(1); }

  is = new_inputstruct(".kilit");
  b = make_jrb();

  while (get_line(is) >= 0) 
  { 

     if(is->NF!=2)
        
      continue;  
     p= strdup(is->fields[0]);  
     ptr= strdup(is->fields[1]);      
     char control=p[0];
     char control2=ptr[0];

    
     if(strcmp(&control,"\""))           
     {
       
      printf( "HATALİ KULLANİM\n");
       exit(1);

     }

     else if(strcmp(&p[strlen(p)-2],"\":"))
     {

       printf( "HATALİ KULLANİM\n");
       exit(1);
     }
      
      /* else if(strcmp(&control2,"\""))
     {
       
      printf( "HATALİ KULLANİM\n");
       exit(1);

     }*/
     /*else if(strcmp(&ptr[strlen(ptr)-2],"\","))
     {
       
      printf( "HATALİ KULLANİM\n");
       exit(1);

     }*/

    else
    {
       p++;
       p[strlen(p)-2] = '\0';
       ptr++;                 
       ptr[strlen(ptr)-2] = '\0';
    }
     
     
  	// printf("%s\n",p);
    

    printf("kelime değeri : %s  kelime : %s  değer: %s\n",&control2,p,ptr);

   // (void) jrb_insert_str(b, p, new_jval_s(ptr));
    //free(p);
    //free(ptr);
  }

   /* jrb_traverse(bn, b) {
    printf("%s\t", bn->key.s);
    printf("%s\n", bn->val.s); 
  }*/
  // EN SON AĞACI SİLMEYİ UNUTMA
  return 0;
}