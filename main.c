#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"
#include "errno.h"
#define ENOENT 2

int main(int argc, char **argv)
{ 

  JRB b;
  JRB bn;
  IS is;
  IS is1;
  char *p;
  char *ptr;
  int sayac=0;
  int sayac1=0;

if (argc != 4) { fprintf(stderr, "usage: $> kripto -d giriş_metin cikis_metin\nkripto -e giriş_metin cikis_metin\n"); exit(1); }

  is = new_inputstruct(".kilit");//ilk while kaç adet satır var onu aldık
  if(is==NULL)
  {
      perror("Kilit dosyası bulunamadı");
      exit(1);
  }

  while (get_line(is) >= 0)
  {
    sayac++;     // sayacı saydırdık
  }
  jettison_inputstruct(is);

is = new_inputstruct(".kilit");
  if(is==NULL)
  {
      perror("Kilit dosyası bulunamadı");
      exit(1);
  }

  b = make_jrb();

  while (get_line(is) >= 0) 
  { 
    //printf("%d\n",is->line);
    sayac1++;
    p= strdup(is->fields[0]);  
    if(sayac1==1)
    {
      if(strcmp(p,"{"))
      {
      printf("Parantez Hatası\n");
      exit(1);
      }
    }

      if(sayac1==sayac)
      {
        if(strcmp(p,"}"))
      {
       printf("Parantez Hatası\n");
       exit(1);
      }
      }

     if(is->NF!=2)
        
      continue;  
     
     
     ptr= strdup(is->fields[1]);
     char control2=ptr[0]; 

      char ch='"';
      char ch1='\\';
      char *value;
      char *value1;
      char *value3;
      value=strchr(p,ch);

   if(value!=p)
   {
      printf( "Json Format Hatası\n");
      exit(1);
   }
     
     else if(strcmp(&p[strlen(p)-2],"\":"))
     {

       printf( "Json Format Hatası\n");
       exit(1);
     }
          
      if(control2!='\"')
     {
       
      printf("Json Format Hatası\n");
       exit(1);

     }
    
    p++;
    p[strlen(p)-2] = '\0';

    if (sayac-1==sayac1)  
    {
      if(strcmp(&ptr[strlen(ptr)-1],"\""))
      {
        printf("Json Format Hatası\n");
        exit(1); 
      }
      ptr++;
    ptr[strlen(ptr)-1] = '\0';
    }
    else 
    {
      if(strcmp(&ptr[strlen(ptr)-2],"\","))
     {
       
      printf("Json Format Hatası\n");
      exit(1);  
     
     }
      ptr++;
    ptr[strlen(ptr)-2] = '\0';
    }
    
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
    if(!strcmp(argv[1],"-e"))
    {
      (void) jrb_insert_str(b, p, new_jval_s(ptr));
    }
       if(!strcmp(argv[1],"-d"))
    {
      (void) jrb_insert_str(b, ptr, new_jval_s(p));
    }  
  }

is1 = new_inputstruct(argv[2]);
FILE *fptr;
  fptr = fopen(argv[3],"w");

while(get_line(is1) >= 0)
{
for(int i=0;i<is1->NF;i++)
{
 char *deger=strdup(is1->fields[i]);
 int kontrol=0;
 jrb_traverse(bn, b) 
 {
   
  if(!strcmp(deger,bn->key.s))
  {
    fprintf(fptr,"%s ",bn->val.s);
    kontrol=1;
  }  
 }

  if(kontrol==0)
  {
    fprintf(fptr,"%s ",is1->fields[i]);
  }
} 
}    jettison_inputstruct(is);
     jettison_inputstruct(is1);
     fclose(fptr);
     jrb_free_tree(b);
return 0;
}