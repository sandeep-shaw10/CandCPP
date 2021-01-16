#include <stdio.h>

unsigned int long factorial(int short num);

unsigned int long factorial(int short num){
	if(num==0){
		return 1;
	}else{
		return num*factorial(num-1);
	}
}

int main(){
	int short value;
	unsigned int long result;
	int negative = 1;
	
	while(negative){
		printf("Enter a postive number : ");
		scanf("%d",&value);	
		if(value>=0){
			negative = 0;
		}
	}
	
	result = factorial(value);
	printf("The factorial of %d is %ld",value,result);
	
	return 0;
}
