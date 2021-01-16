#include <stdio.h>

unsigned int long fibonacci(int num);

unsigned int long fibonacci(int num){	
	if(num<=1){
		return num;
	}else{
		return fibonacci(num-1)+fibonacci(num-2);
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
	
	result = fibonacci(value-1);
	printf("The fibonacci of %d-th position is %ld",value,result);
	
	return 0;
}
