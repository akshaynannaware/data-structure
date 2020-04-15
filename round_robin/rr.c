#include<stdio.h> 
#include<stdlib.h>

void waiting_time(int n,int arrival_time[],float wt[],int bt[],int quantom){
	int rem_bt[n];
	//int bt[n];int wt[n];
	int temp;
	
	for(int i=0;i<n;i++){	
		rem_bt[i] = bt[i];
	}
	//int wt[n];
	int current_time=0;

	while(1){
		temp=0;
		for(int i=0;i<n;i++){
			if(rem_bt[i]>0){
				temp=1;
				if(rem_bt[i]>quantom){
					current_time = current_time + quantom;
					rem_bt[i] = rem_bt[i] - quantom;
				}
				else{
					current_time = current_time + rem_bt[i];
					wt[i] = current_time - bt[i];
					rem_bt[i] = 0;	
				}
			}
		}
		if(temp==0){
			break;
		}
	}	
}
void turn_arround_time(int n,int bt[],float wt[],float tat[],int arrival_time[]){
	for(int i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
	}

}

void avgtime(int n,int arrival_time[],int bt[],int quantom){
	//printf("%d",n);
	float  wt[n];
	float tat[n];	
	//int rem_bt[n];
	float avg_wt=0;
	float avg_tat=0;

	waiting_time(n,arrival_time,wt,bt,quantom);  //direct function calling from here
	turn_arround_time(n,bt,wt,tat,arrival_time); //function call to find turn around time

	int total_wt;
	int total_tat;
	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
	}
	

	avg_wt = total_wt/n;					//average waiting time
	avg_tat = total_tat/n;					//average turn arround time

	printf("average waiting time: %f\t",avg_wt);
	printf("avearage tat: %f\t",avg_tat);
}
int main(){
		
	int quantom=2;
	
	//printf("enter no. of processess u want to add\n");
	//scanf("%d",&n);
	int arrival_time[3];
	int bt[3];
	//arrival_time=(int *)malloc(sizeof(int)*n);
	//bt=(int *)malloc(sizeof(int)*n);
	
	printf("enter arrival time of each process\n");
	for(int i=0;i<3;i++){
		scanf("%d",&arrival_time[i]);
	}
	int n=sizeof arrival_time/sizeof arrival_time[0];

	printf("enter burst time for each process\n");
	
	//printf("enter quantom time that the loop will get execute\n");
	//scanf("%d",&quantom);	
	for(int i=0;i<3;i++)
		scanf("%d",&bt[i]);
	
	
	
	avgtime(n,arrival_time,bt,quantom);	

	return 0;

	
}
