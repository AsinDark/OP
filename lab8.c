#include<stdio.h>
#include<math.h>
#define E 0.0001

 int main()
  {
  double x;
  double decision();
  void error();
  
  x=decision();
  printf("Искомое число:%.4lf\n",x);
  error(x);
  
  return 0;
  }

 double decision()                    //Деление отрезка пополам
  {
  double a,b,x,y;
  double f(double);
  
  a=0;                                //Начало отрезка
  b=8;                                //Конец отрезка
  
  do
   {
   x=fabs(b-a)/2 + a;
   y=f(x);
   if ((y>0)==(f(a)>0))               //Сравнение знаков значений функции
    a=x;
   else 
    b=x;
   }
  while (fabs(y)>E);
  
  return x;
  }

 double f(double x)                   //Вычисление значениия функции
  {
  double y;
  
  y=cos(0.5*x)-x*x+10;
  
  return y;
  }

 void error(double x)                 //Вычисление погрешности
  {
  double d,D;
  const double xi=3.160761861159747;
  
  d=fabs(xi-x);
  D=d/xi*100;
  printf("Относительная погрешность:%lf%%\n",D);
  printf("Абсолютная погрешность:%lf\n",d);
  }
