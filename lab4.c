#include<stdio.h>
#include<math.h>

 int main()
  {
  int e;
  long double x;
  
  int input1(),input2();
  long double lim();
  void print(); //error();

  printf("Введите количество символов после запятой в диапазоне от 1 до 18:\n");  
  e=input2(18 , 1);
  x=lim(e);
  print(x,e);
  //error(x);
  }
 
 int input1(void)                   //Проверка ввода на посторонние символы
  {
  int n;
  while (scanf("%d",&n)!=1) 
   {
   printf("Необходимо ввести число. Попробуйте ещё раз.\n");
   while (getchar()!='\n')
   ;
   }
  return n;
  }
 
 int input2(int max, int min)        //Проверка диапазона
  {
  int n;
  while (((n=input1())>max) || (n<min))
   {
   printf("Ошибка диапазона. Попробуйте ещё раз.\n");
   while (getchar()!='\n')
   ;
   }
  return n;
  }

 double fib(int k)                 //Вычисление чисел Фибоначчи
  { 
  int i,t;
  long f1,f2;
  f1=1;
  f2=1;
  for (i=1; i<k; i++)
   {
   t=f1;
   f1=f2;
   f2+=t;
   }
  return f2;
  }
  
 long double lim (int e)            //Вычисление предела отношения соседних чисел Фибоначчи
  {
  long double E,x;
  int n;
  E=powl(10,-(e+1));
  n=0;
  while (fabsl(fib(n+2)/fib(n+1)-fib(n+1)/fib(n))>E)
   {
   n++;
   }
   x=fabsl(fib(n+2)/fib(n+1));
  printf("Количество итераций:%d\n", n);
  return x; 
  }  
   
 void print(long double x, int e)     //Округление и вывод
  {
  long n;
  x=x-1;                             //Избавляемся от целой части
  x=x*pow(10,e+1);                   //Приводим нужное количество разрядов к целой части
  n = x;                             //Отбрасываем оставшуюся дробную часть
  if (n%10 >= 5)                     //Производим округление
   {
   n=n+10-(n%10);
   }
  n=n/10; //Отбрасываем последний разряд
  printf("Искомое число:1.%ld\n",n);
  } 

 /*void error(long double x)
  {
  long double A,d,D;
  A=(1+sqrtl(5))/2;
  d=fabsl(A-x);
  D=100*d/A;
  printf("Абсолютная погрешность:%.30LF\n",d);
  printf("Относительная погрешность:%.30LF%%\n",D);
  }*/ 