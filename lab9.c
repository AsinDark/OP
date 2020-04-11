#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 8

 int main()
 {
  int mass[N][N], res[N], max;
  int maxres(int[N]);
  void fillmass1(int[N][N]), fillmass2(int [N][N]), filld(int[N][N]);
  void sum(int[N],int[N][N]), print(int[N],int);
  
  srand(time(NULL));
  filld(mass);
  fillmass1(mass);
  fillmass2(mass);
  sum(res,mass);
  max=maxres(res);
  print(res,max);
  return 0;
 }

 void filld(int mass[N][N])
 {
  int i;
  for (i=0;i<N;i++)
  {
   mass[i][i]=0;
  }
 }

 void fillmass1(int mass[N][N])
 {
  int i,j;
  for (i=0;i<N;i++)
  {
   for (j=0;j<i;j++)
   {
    mass[i][j]=rand()%4;
    while (mass[i][j]==2)
     mass[i][j]=rand()%4;
   }
  }
 }

 void fillmass2(int mass[N][N])
 {
  int i,j;
  for (i=0;i<N;i++)
  {
   for (j=0;j<i;j++)
   {
    switch (mass[i][j])
    {
     case 0 :
      mass[j][i]=3;
      break;
     case 1 :
      mass[j][i]=1;
      break;
     case 3 :
      mass[j][i]=0;
      break;
    }
   }
  }
 }

 void sum(int res[N] , int mass[N][N])
 {
  int i,j;
  for (i=0;i<N;i++)
  {
   res[i]=0;
   for (j=0;j<N;j++)
   {
    res[i]+=mass[i][j];
   }
  }
 }

 int maxres(int res[N])
 {
  int max,i;
  max=0;
  for (i=0;i<N;i++)
  {
   if (max<res[i])
   {
    max=res[i];
   }
  }
  return max;
 }

 void print(int res[N],int max)
 {
  int i;
  for (i=0;i<N;i++)
  {
   printf("Очки команды %d: %d.\n", i+1, res[i]);
  }
  printf("Максимальное количество очков:%d\n",max);
  printf("Команды, набравшие максимальное количество очков:");
  for (int i=0;i<N;i++)
  {
   if (res[i]==max)
   {
    printf(" %d",i+1);
   }
  }
  printf("\n");
 }