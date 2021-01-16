#include <stdio.h>

unsigned int long gcd(int a, int b);

unsigned int long gcd(int a, int b){	
	if(a==0){
		return b;
	}else{
		return gcd(b%a,a);
	}
}

int main(){
	int val1, val2;
	unsigned int long result;
	int negative = 1;
	
	while(negative){
		printf("  Enter the first value : ");
		scanf("%d",&val1);
		printf(" Enter the second value : ");
		scanf("%d",&val2);
		if(val1>0 & val2>0){
			negative = 0;
		}
	}
	
	result = gcd(val1, val2);
	printf("   The GCD of %d and %d is %d \n",val1,val2,result);
	result = (val1 * val2)/result;
	printf("   The LCM of %d and %d is %d ",val1,val2,result);	
	
	return 0;
}
