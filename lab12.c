#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 128

 struct words { char *word;
                int num;
                struct words *next;
              } *first=NULL, *last=NULL;

 FILE *fp;
 
 int main()
 {
  void shift(char*),out();
  struct words* check(char*);
  char buff[N],c, *p_word;
  int i;
  
  fp=fopen("logfile","w");
  if (fp==NULL)
  {
   printf("Ошибка открытия файла");
   exit(1);
  }
  i=0;
  while ((c=getchar()) != EOF)
  {
   if ((c!=' ') && (c!='\t') && (c!='\n'))
   {
     if (i>N)
     {
      exit(2);
      printf("Буффер переполнен");
     }
     buff[i]=c;
     i++;
   }
    else
    {
     buff[i]='\0';
     if ((p_word=(char*)malloc(strlen(buff)+1))==NULL)
     {
      printf("Ошибка выделения памяти.");
      exit(1);
     }
     strcpy(p_word, buff);
     if (((last=check(p_word))!= NULL) || (first == NULL))
      shift(p_word);
     i=0;
    }
   }
  out();
  fclose(fp);
 } 

 void shift(char *p_word)
 {
   struct words *tmp;
   if((tmp=(struct words *)malloc(sizeof(struct words)))==NULL)
   {
    printf("Ошибка выделения памяти.");
    exit(2);
   }
    if (first==NULL)
    {
     tmp->word = p_word;
     tmp->num=1;
     first=tmp;
     last=tmp;
    }
    else
    {
     tmp->word = p_word;
     tmp->num=1;
     tmp->next = NULL;
     last->next = tmp;
     last=tmp;
    }
 }

 struct words* check(char *p_word)
 {
  struct words *p;
  for(p=first;p!=NULL;p=p->next)
  {
   if(!strcmp(p->word, p_word))
   {
    p->num++;
    return NULL;
   }
  if (p->next==NULL)
   return p;
  }
 return p;
 } 

 void out(void)
{
 struct words *p;
 while (first != NULL)
 { 
  p=first;
  fprintf(fp,"Слово:%s;  Количество повторений: %d\n",first->word, first->num);
  first=first->next;
  free(p->word);
  free(p);
 }
}
 