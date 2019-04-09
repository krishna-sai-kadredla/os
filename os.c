#include<stdio.h>
#include<pthread.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
void *fun1(void *a);
void *fun2(void *a);
 int *q;
void *fun1(void *a)
{ int *d=(int *)a;
  pthread_t th2;
  int n=*d;
  int first,second,sum=0,i=1;
  int arr[n];
  first=-1;
  second=1;
  while(i<=n)
   {  sum=first+second;
      first=second;
      second=sum;
      arr[i-1]=sum;
      i++;
   }
   q=arr;
   pthread_create(&th2,NULL,fun2,&n);
   pthread_join(th2,NULL);
}
void *fun2(void *a)
{  int *k=(int *)a;
   int n=*k;;
   for(int i=0;i<n;i++)
     printf(" %d ",*(q+i));
}
void main()
{
int a;
pthread_t th1;
printf("Enter value of a\n");
scanf("%d",&a);
pthread_create(&th1,NULL,fun1,&a);
pthread_join(th1,NULL);
}

