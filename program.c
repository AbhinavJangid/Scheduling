#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()

{

  int counted,number,t_time,rem,flag=0,quantum;

  int waiting=0,turnaround=0,arrival_time[10],burst_time[10],remaining_time[10];
  
  printf("Enter Total Process:\t ");

  scanf("%d",&number);

  rem=number;

  for(counted=0;counted<number;counted++)

  {

    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",counted+1);

    scanf("%d",&arrival_time[counted]);

    scanf("%d",&burst_time[counted]);

    remaining_time[counted]=burst_time[counted];

  }

  printf("Enter Time Quantum:\t");
  
  scanf("%d",&quantum);

  for(t_time=0,counted=0;rem!=0;)

  {
    if(remaining_time[counted]<=quantum && remaining_time[counted]>0)

    {

      t_time+=remaining_time[counted];

      remaining_time[counted]=0;

      flag=1;

    }

    else if(remaining_time[counted]>0)

    {

      remaining_time[counted]-=quantum;

      t_time+=quantum;

    }


    if(remaining_time[counted]==0 && flag==1)

    {

      rem--;

      printf("P[%d]\t|\t%d\t|\t%d\n",counted+1,t_time-arrival_time[counted],t_time-arrival_time[counted]-burst_time[counted]);

      waiting+=t_time-arrival_time[counted]-burst_time[counted];

      turnaround+=t_time-arrival_time[counted];

      flag=0;

    }

    if(counted==number-1)

    counted=0;

    else if(arrival_time[counted+1]<=t_time)

    counted++;

    else

    counted=0;
  }

  
  printf("\nAverage Waiting Time= %f\n",waiting*1.0/number);

  printf("Avg Turnaround Time = %f",turnaround*1.0/number);

  return 0;

}
