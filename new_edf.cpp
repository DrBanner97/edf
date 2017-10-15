#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,job[10],burst[10],newburst[10],arrival[10],deadline[10],wt[10],turn[10];
	int tot_turn=0,tot_wait=0,avg_turn=0,avg_wait=0,i,j,m,temp;
	int curr_time=1000,no_of_process,current_turn=0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	no_of_process=n;
	printf("\n");

	printf("Enter arrival time, burst time and deadline of processes (0 for none):\n");
	for(m=0;m<n;m++)
	{
		scanf("%d %d %d",&arrival[m],&burst[m],&deadline[m]);
		job[m]=m;
		if(arrival[m]<curr_time){
			curr_time=arrival[m];
		}
		if(deadline[m]==0)
		{
			deadline[m]=1000;
		}
	}
    
    //sorting in ascending order w.r.t deadline
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
         
            if(deadline[i] < deadline[j])
            {
                temp=deadline[i];
                deadline[i]=deadline[j];
                deadline[j]=temp;

                temp=job[i];
                job[i]=job[j];
                job[j]=temp;

                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;


                temp=arrival[i];
                arrival[i]=arrival[j];
                arrival[j]=temp; 
            }
          
       }
    }

	printf("\n");
    
	
	while(no_of_process>0){
		if(curr_time>=arrival[i%n]){
		
			if(deadline[i%n]>=(curr_time+burst[i%n])){
				printf("Job %d assigned at %d\n",job[i%n]+1,curr_time);
				curr_time+=burst[i%n];
				no_of_process--;
								
				current_turn=(curr_time-arrival[i%n]);
				tot_turn+=current_turn;
				tot_wait+=(current_turn-burst[i%n]);
				
				arrival[i%n]=1000;
			}
			else if(deadline[i%n]==1000 || deadline[i%n]<(curr_time+burst[i%n])){  //if process misses deadline
					printf("Job %d deadline missed\n",job[i%n]);
					deadline[i%n]=1000;  //deadline once missed can be re-scheduled by extending deadline
			
			}
		}
		i++;
	}
	
	
	printf("\nAverage Turn Around Time= %f\n",((float)tot_turn/n));
	printf("Average Wait Time= %f",((float)tot_wait/n));
	return 0;	
}

