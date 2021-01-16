#include <stdio.h>

unsigned int long fibonacci(int a, int b, int num);

unsigned int long fibonacci(int a, int b, int num){	
	if(num==1){
		return a;
	}else{
		num=num-1;
		return fibonacci(b,a+b,num);
	}
}

int main(){
	int value;
	unsigned int long result;
	int negative = 1;
	
	while(negative){
		printf("Enter a nth position number : ");
		scanf("%d",&value);	
		if(value>0){
			negative = 0;
		}
	}
	
	result = fibonacci(0,1,value);
	printf("The fibonacci of %d-th position is %ld",value,result);
	
	return 0;
}
