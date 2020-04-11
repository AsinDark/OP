#include<stdio.h>
#define N 7

 int main()
 {
 void zeroing(int[]), inout(int[]), print(int[]);
 int mass[N];

 zeroing(mass);
 inout(mass);
 print(mass);
 }

 void zeroing(int mass[])
 {
  int i;
  for (i=0; i<N; i++)
  {
   mass[i]=0;
  }
 }
 
 void inout(int mass[])
 {
  char c;
  int counter(char,int[]);
  while ((c=getchar())!=EOF)
  {
   counter(c,mass);
   putchar(c);
  }
 }

 int counter(char c, int mass[])
 {
  mass[0]++;                                                //Все символы
 if (c=='\n')                                               //Строки
  mass[1]++;
 if ((c==' ') || (c=='\n'))                                 //Слова
  mass[2]++;
 if ((c>='\0') && (c<' '))                                  //Управляющие символы
 {                                 
  mass[3]++;
  return;
 } 
  else
   if ((c>='0') && (c<='9'))                                //Цифры
   {
    mass[4]++;
    return;
   }
    else
     if ((c>='A') && (c<='Z') || (c>='a') && (c<='z'))      //Буквы
     {
      mass[5]++;
      return;
     }  
      else
       if ((c=='+') || (c=='-') || (c=='/') || (c=='*'))    //Знаки операций
       {
        mass[6]++;
        return;
       }
 }

 void print(int mass[])
 {
  printf("Количество символов: %d\n",mass[0]-mass[2]);
  printf("Количество строк: %d\n",mass[1]);
  printf("Количество слов: %d\n",mass[2]);
  printf("Количество управляющих символов: %d\n",mass[3]);
  printf("Количество цифр: %d\n",mass[4]);
  printf("Количество букв: %d\n",mass[5]);
  printf("Количество знаков операций: %d\n",mass[6]);
 }
   
