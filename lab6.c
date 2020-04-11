#include<stdio.h>
#define C 5

 int main()
  {
  int base,div;
  double rem,num;
  double input2(int,int);
  int Integer(int,int);
  void Fraction(double, int);
  
  printf("Введите число, которое хотите перевести в другую систему счисления (до 10 знаков):");
  num=input2(-1000000000,1000000000);
  
  printf("Введите новое основание системы счисления (от 2 до 16):");
  base=input2(2,16);
  
  if (num<0)                     //Проверка на отрицательные числа
   {
   num=-num;
   printf("-");
   }
  div=(int)num*base;             //Целая часть числа * на основание системы счисления
  rem=num-(int)num;              //Дробная часть числа
  
  Integer(base,div);
  
  if (rem!=0)
   {
   Fraction(rem,base);
   }
   printf("\n");
  }

 double input1(void)             //Ввод и проверка корректности ввода
   {
   double n;
  
    while (scanf("%lf",&n)!=1)
     {
     printf("Необходимо ввести число. Попробуйте ещё раз.\n");
     while (getchar()!='\n')
     ;
     }
   return n;
   }

 double input2(int min, int max)        //Проверка диапазона
  {
  double n;
 
   while (((n=input1())>max) || (n<min))
   {
   printf("Ошибка диапазона. Попробуйте ещё раз.\n");
   while (getchar()!='\n')
   ;
   }
  return n;
  }

 int Integer(int base, int div)         //Перевод целой части
  {
  int mod;
  
  while ((div/base)>=1)
   {
   div/=base;
   Integer(base,div);                   //Рекурсия
   mod=div%base;
   printf("%x",mod);
   return 1;
   }
  }

 void Fraction(double rem, int base)     //Перевод дробной части
  {
  int i,div;
  
  printf(".");
  i=0;
  div=0;
  
  while((i<=C) && ((rem-div)!=0))
   {
   rem*=base;
   div=rem;
   rem-=div;
   printf("%x",div);
   i++;
   }
  }
