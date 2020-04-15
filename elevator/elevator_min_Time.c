#include<stdio.h>

int i,j;


int minimum_Time(int n, int k, int a[]) 
{ 
	int temp;
	for (i = 0; i < n; i++){
		for (j = i + 1; j < n; j++){
			if(a[i] < a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
				
		}
	}
	int minTime = 0; 
  
   
	for (int i = 0; i < n; i += k) 
  		
		minTime += (2 * a[i]); 
  
	return minTime; 
} 
  
int main() 
{ 
	int per,n;
	printf("enter number of persons\n");	
	scanf("%d",&per);
	printf("enter number floars \n");
	scanf("%d",&n);
	 
	int arr[n];
	
	printf("enter number of floars u want to go\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	//minimum_Time(n, per, arr);
	printf("Minimum time taken by lift is :\t%d\n",minimum_Time(n, per, arr)); 
  
    return 0; 
} 

