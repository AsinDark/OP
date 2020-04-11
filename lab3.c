#include<stdio.h>
#include<math.h>

 int in(void)       //Проверка правильности ввода
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
 
 int main()
  {
  float D,x1,x2,a,b,c;
  
  while ((a=in())==0) //Ввод коэффициента a
   {
   printf("Недопустимое значение. Попробуйте ещё раз.\n");
   }
  b=in();           //Ввод коэффициента b
  c=in();           //Ввод коэффициента c
  
  D=b*b-4*a*c;      //Вычисление дискриминанта
    
   if (D==0)        //1 корень
    {
    x1=(0-b)/(2*a);
    printf("x=%.2f",x1); 
    }
    else 
     {
     if (D>0)        //2 действительных корня
      {
      x1=((0-b)+(sqrtf(D)))/(2*a);
      x2=((0-b)-(sqrtf(D)))/(2*a);
      printf("x1=%.2f\nx2=%.2f",x1,x2); 
      } 
      else           //2 мнимых корня 
       { 
       x1=(0-b)/(2*a);
       x2=(sqrtf(fabs(D)))/(2*a); 
       printf("x1=%.2f+i*%.2f\n",x1,x2);
       printf("x2=%.2f-i*%.2f",x1,x2);
       }
     }
   return 0;
  }
  