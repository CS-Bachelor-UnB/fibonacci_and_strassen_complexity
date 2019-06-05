#include "fibonacci.h"

long long loop(int n)
{
	long long arr[n];
	if(n<1){
		printf("Bad Parameter");
		return -1;
	}
	if(n==1||n==2){
		return 1;
	}
	arr[0]=1;
	arr[1]=1;
	for(int i = 2; i<n; i++){
		arr[i]=arr[i-2]+arr[i-1];
	}
	return arr[n-1];
}
