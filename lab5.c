#include<stdio.h>

 int main()
  {
  int n;
  void f1(int),f2(int),f3(int);
  int input1(void),input2(int,int);
  
  n=input2(1,100);
  printf("Вам %d",n);              //Первая надпись
  f1(n);
  f2(n);			
  f3(n);
  }
 
 int input1(void)                  //Ввод и проверка корректности ввода
   {
   int n;
  
    while (scanf("%d",&n)!=1)
     {
     printf("Необходимо ввести число от 1 до 100. Попробуйте ещё раз.\n");
     while (getchar()!='\n')
     ;
     }
   return n;
   }

 int input2(int min, int max)        //Проверка диапазона
  {
  int n;
 
   while (((n=input1())>max) || (n<min))
   {
   printf("Необходимо ввести число от 1 до 100. Попробуйте ещё раз.\n");
   while (getchar()!='\n')
   ;
   }
  return n;
  }

 void f1(int n)                       //Вывод год, года или лет
  {
  int a;
  
  a=n%10;
 
  if ((n/10)==1)
   {
   printf(" лет.\n");
   }
  else
   {
   switch (a)
    {
    case 1 :
     printf(" год.\n");
     break;
    case 2 :
     case 3 :
      case 4 :
       printf(" года.\n");
     break;
    default :
     printf(" лет.\n");
     break;
    }
   } 
  }

 void f2(int n)                       //Вторая надпись
  {
  int x;

  if (n>18)
   {
   x=n-18;
   printf("Вы совершеннолетний %d",x);
   f1(x);
   }
  else 
   {
   if (n==18)
    {
    printf("Вы совершеннолетний.\n");
    }
    else
     {
     x=18-n;
     printf("Вам до совершеннолетия %d",x);
     f1(x);
     }
    }
  }

 void f3(int n)                        //Третья надпись
  {
  int x;

  if (n>60)
   {
   x=n-60;
   printf("Вы на пенсии %d",x);
   f1(x);
   }
  else 
   {
   if (n==60)
    {
    printf("Вы пенсионер.\n");
    }
    else
     {
     x=60-n;
     printf("Вам до пенсии %d",x);
     f1(x);
     }
    }
  }
