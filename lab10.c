#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define N 100

 int main()
 {
  void isfull(int), print(char*[]);
  char* string(char[], char*, int);
  char buff[N],c;
  char *line_num[N],*a;
  int i,j;
  i=0;
  j=0;
  while ((c=getchar()) != EOF)
  {
   if ((c!=' ') && (c!='\t'))
    if (c!='\n')
    {
     buff[i]=c;
     i++;
     isfull(i);
    }
    else
     {
      buff[i]='\0';
      a=string(buff,a,i);
      line_num[j]=a;
      j++;
      i=0;
     }
  }
  line_num[j]=NULL;
  print(line_num);
  free(a);
 }
 
char* string (char buff[] , char* a, int j)
 {
  int i;
  if ((a=(char*)malloc(strlen(buff)+1))==NULL)
  {
   printf("Не хватает памяти для числа.");
   exit(1);
  }
  for (i=0; i<=j;i++)
   a[i]=buff[i];
 return a;
 }

 void print(char* line_num[])
 {
  int i;
  i=0;
  putchar('\n');
  while (line_num[i]!=NULL)
  {
   printf("%s",line_num[i]);
   i++;
   putchar('\n');
  }
 }

 void isfull(int i) 
 { 
 if(i>N) 
  { 
  printf("Выход за пределы массива"); 
  exit(1); 
 } 
} 