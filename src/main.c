#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"
#include "errno.h"
int main(int argc, char **argv)
{ 

  JRB b;
  JRB bn;
  IS is;
  char *p;
  char *ptr;

if (argc != 2) { fprintf(stderr, "usage: $> kripto -d giriş_metin cikis_metin\n"); exit(1); }

  is = new_inputstruct(".kilit");
  if(is==NULL)
  {
      perror("Kilit dosyası bulunamadı");
  }
  b = make_jrb();

  while (get_line(is) >= 0) 
  { 
    
     if(is->NF!=2)
        
      continue;  
     
     p= strdup(is->fields[0]);  
     ptr= strdup(is->fields[1]);
     char control2=ptr[0];      
     char control=p[0];

      char ch='"';
      char ch1='\\';
      char *ch2="\\\"";
      char *value;
      char *value1;
      char *value2;
      char *value3;
      value=strchr(p,ch);

   if(value!=p)
   {
      printf( " 1.kullanım HATALİ KULLANİM\n");
      exit(1);
   }
     

     else if(strcmp(&p[strlen(p)-2],"\":"))
     {

       printf( "2. kullanımHATALİ KULLANİM\n");
       exit(1);
     }
     
      
      if(strcmp(&control2,"\""))
     {
       
      printf( "3.kullanım HATALİ KULLANİM\n");
       exit(1);

     }
     else if(strcmp(&ptr[strlen(ptr)-2],"\","))
     {
       
      printf( "4.kullanım HATALİ KULLANİM\n");
      exit(1);  
     
     }
    
    p++;
    p[strlen(p)-2] = '\0';

    ptr++;
    ptr[strlen(ptr)-2] = '\0';
    
    value1=strchr(p,ch1);

    if(value1==p)
    {
      p++;
    }

   value3=strrchr(p,ch1);

   if(value3!=NULL)
   {
     if(strlen(value3)==2)
     {
       p[strlen(p)-2]='\"'; 
       p[strlen(p)-1]= '\0';
     }
     else if(strlen(value3)>2)
     {
       char *temp=&p[strlen(p)-strlen(value3)+1];
       for(int i=0;i<=strlen(value3);i++)
       {
         p[strlen(p)-strlen(value3)+i]=temp[i];
       }
     }
   }

   //printf("kelime : %s  değer: %s\n",p,ptr);
    
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