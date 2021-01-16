#include <stdio.h>
#include <stdlib.h>
//#define max 100

int linear_search(int ptr[], int item, int upper);

int linear_search(int ptr[], int item, int upper){
	if(upper==0){
		return -1;
	}else if(ptr[upper]==item){
		return 1;
	}else{
		upper-=1;
		linear_search(ptr,item,upper);
	}
}


int main(){
	int i, size, item, result;
	int *ptr;
	
	printf("ENTER THE SIZE OF ARRAY : ");
	scanf("%d",&size);
	
	ptr = malloc(size * sizeof(*ptr));
	
	if(ptr != NULL){
		
		for(i=0;i<size;i++){
		printf(" Enter element at position %d = ",i+1);
		scanf("%d",&ptr[i]);
		}
		
		printf("\n\n Enter the element to be searched = ");
		scanf("%d",&item);
	
		result = linear_search(ptr,item,size-1);
	
		if(result==-1){
			printf(" Element is not present");
		}else{  
			printf(" Element exist");
		}
		
	}else{
		printf("Memory can't be allocated'");
	}
	
	free(ptr);
	
	return 0;
}
