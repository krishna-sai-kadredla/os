
#include<stdio.h>
#include<stdlib.h>
int main()
 {
  int n,first;
  int last,capacity;
  int i,j,avail;
  int curloc,ploc,loc;
  printf("Disk scheduling Algorithm of SCAN\n");
  printf("Please enter the disk drive capacity\n");
  scanf("%d",&capacity);
  printf("Please enter the starting disk track number of cylinder\n");
  scanf("%d",&first);
  printf("Please enter the terminating disk track number of cylinders\n");
  scanf("%d",&last);
  printf("Please enter the current location\n");
  scanf("%d",&curloc);
  printf("Please enter previous location\n");
  scanf("%d",&ploc);
  printf("Please enter the total number locations\n");
  scanf("%d",&n);
  int size=n;
  int array[size];
  printf("enter the each and every values of the cylinder\n");
  for(i=0;i<n;i++)
	{
	  scanf("%d",&array[i]);
	}
  for(i=0;i<n;++i)
  {
      for(j=i+1;j<n;++j)
      {
          if(array[i]>array[j])
          {
              avail=array[i];
               array[i]=array[j];
               array[j]=avail;
          }
      }
      
  }
  for(i=0;i<n;i++)
	{
	 if(curloc==array[i])
	    {
	      loc=i;
	      break;
 	    }
	}
  if(curloc<ploc)
	{
	 int sum=0,sum1=0,sum2=0;
	 printf("the order of execution is as follows\n");
	 for(i=loc;i>=0;i--)
		{
		 printf("-->%d ",array[i]);
		}
	 printf("-->%d ",first);
    	 for(i=loc+1;i<n;i++)
	 	{
		 printf("-->%d",array[i]);
		}
    	 for(i=loc;i>=1;i--)
		{
		 sum1=sum1+array[i]-array[i-1];
		}
	 for(i=loc+1;i<n-1;i++)
	 	{
		 sum2=sum2+array[i+1]-array[i];
		}
         sum=(sum1+sum2+(array[loc+1]-first)+(array[0]-first));
         printf("\ntotal distance (in cylinders)that the disk arm moves to execute all the pending requests is %d",sum);
	}
   else if(curloc==ploc)
	{
	 printf("you have entered the same previous and present locations\n");
	 exit(0);
	}
   else
	{
	 int sum1=0,sum2=0,sum=0;
	 printf("the order of execution is as follows\n");
    	 for(i=loc;i<n;i++)
	 	{
		 printf("-->%d",array[i]);
		}
         printf("-->%d ",last);
         for(i=loc-1;i>0;i--)
		{
		 printf("-->%d ",array[i]);
		}
    	 for(i=loc;i<n-1;i++)
	 	{
		 sum1=sum1+array[i+1]-array[i];
		}
         for(i=loc-1;i>=1;i--)
		{
		 sum2=sum2+array[i]-array[i-1];
		}
	 sum=(sum1+sum2+(last-array[n-1])+(last-array[loc-1]));
         printf("\ntotal distance (in cylinders)that the disk arm moves to satisfy all the pending requests is %d",sum);
	}
 }
