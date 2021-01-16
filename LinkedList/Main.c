//including packages
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//defining the function assignment specific
void display_array(int arr[], int size);
void random_assign(int arr[], int size, int limit);
void first_insert(int arr[], unsigned int size);
void random_insert(int arr[], unsigned int size, int limit);
void first_delete(int arr[], unsigned int size);
void random_delete(int arr[], unsigned int size, int limit);
struct pair get_minmax(int arr[], unsigned int size, int limit);
void bubble_sorting(int arr[], unsigned int size,  int limit);
struct position get_position(int arr[], unsigned int size);

//global variable
struct pair{ 
  int min; 
  int max; 
};

struct position{
	int i;
	int j;
};


//function
void display_array(int arr[], int size){
	int i;
	for(i=0;i<size;i++){
		if(arr[i]==-1){
			printf("Null ");
		}else{
			printf("%d ",arr[i]);			
		}
	}
	printf("\n\n");
}

void random_assign(int arr[], int size, int limit){
    int i;
    printf("[ STEP - 1 : Assigning the random value and displaying ]\n");
    for(i = 0; i<limit ; i++){
        arr[i] = rand()%1000;
    }
    display_array(arr,size);
}

void first_insert(int arr[], unsigned int size){
	int i, value;
    printf("\n\n[ STEP - 2 : Inserting a new element at the beginning of an array. ]\nEnter a Value : ");
    scanf("%d",&value);

    //Shifting the value one by one
    i = size-1;
    while(i!=0){
        arr[i]=arr[i-1];
        i--;
    }
    
    //Insering the value at the position 
    arr[0]=value;
    
    display_array(arr,size);
}

void random_insert(int arr[], unsigned int size, int limit){
	int i, value, pos;
    printf("\n\n[ STEP - 3 : Insert a new element at the kth position of the array. Kth position being obtained randomly. ]\nEnter a Value : ");
    scanf("%d",&value);
    //Generating random position
    pos = rand()%size+1;
    printf("\n - - - - >> Your value %d, has been succesfully inserted at position %d \n\n",value,pos);

    //Shifting the value one by one after the pos
    i = limit-1;
    while(i!=pos-1){
        arr[i]=arr[i-1];
        i--;
    }
    
    //Insering the value at the position 
    arr[pos-1]=value;
    
    display_array(arr,size);
}

void first_delete(int arr[], unsigned int size){
	int i;
    printf("\n\n[ STEP - 4 : Deleting the element from the beginning of an array. ]\n");
    
    //Shifting the value one by one forward
    i=0;
    while(i!=size-1){
        arr[i]=arr[i+1];
        i++;
    }
    
    //Assigning a null value (-1) at the end to prevent the occurence of the gatbage Value
    arr[size-1] = -1;
    
    display_array(arr,size);
}

void random_delete(int arr[], unsigned int size, int limit){
	int i,pos,check=1;
    printf("\n\n[ STEP - 5 : Delete an element from the kth position of the array . Kth position being obtained randomly. ]\n");
    //Generating random position
        pos = rand()%limit+1;
    printf("\n - - - - >> Value %d has been succesfully deleted at position %d \n\n",arr[pos-1],pos);
    //Shifting the value one by one forward
    i=pos-1;
    while(i!=limit-1){
        arr[i]=arr[i+1];
        i++;
    } 
    //Assigning a null value (-1) at the end to prevent the occurence of the gatbage Value
    arr[limit-1] = -1;
    
    display_array(arr,size);
}

struct pair get_minmax(int arr[], unsigned int size, int limit){
	struct pair minmax;
	int high,low,i;
	if(limit == 0){
		minmax.min = -1;
		minmax.max = -1;
		return minmax;
	}else{
		if(limit%2==0){
			if(arr[0]>arr[1]){
				minmax.max=arr[0];
				minmax.min=arr[1];
			}else{
				minmax.max=arr[1];
				minmax.min=arr[0];				
			}
			
		for(i=2;i<limit;i=i+2){
			if(arr[i]>arr[i+1]){
				high=arr[i];
				low=arr[i+1];
			}else{
				high=arr[i+1];
				low=arr[i];				
			}
				
			if(high>minmax.max){
				minmax.max=high;				
			}
	
			if(low<minmax.min){
				minmax.min=low;				
			}									
		}
			
		return minmax;	
			
		}else{
			minmax.max=arr[0];
			minmax.min=arr[0];
			
			for(i=1;i<limit;i=i+2){
			if(arr[i]>arr[i+1]){
				high=arr[i];
				low=arr[i+1];
			}else{
				high=arr[i+1];
				low=arr[i];				
			}
				
			if(high>minmax.max){
				minmax.max=high;				
			}
	
			if(low<minmax.min){
				minmax.min=low;				
			}									
		}
		
		return minmax;
				
		}
	}
}

void bubble_sorting(int arr[], unsigned int size, int limit){
    int i, j, temp; 
    printf("\n\n[ STEP - 7 : Sort the array of (6) using bubble sort. ]\n");
    for (i = 0; i < limit-1; i++){
    // Last i elements are already in place    
        for (j = 0; j < limit-i-1; j++){
                if (arr[j] > arr[j+1]){
                temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
            }
        } 
    }
    
    display_array(arr,size);
}

struct position get_position(int arr[], unsigned int limit){
	int x, sum, upper, lower; 
	struct position get;
    printf("\n\n[ STEP - 8 : Find two indices i and j such a[i]+a[j]=k, where k is obtained from user and array of (6) is the array �a�. O(n) ]\n");
    printf("Enter the sum to be searched : ");
    scanf("%d",&sum);
    printf("\n");
	
	get.i=-1;
    get.j=-1;
    	
    if(arr[0]+arr[1]>sum || arr[limit-1]+arr[limit-2]<sum){
    	return get;
	}else{
		lower=0;
		upper=limit-1;
		
		while(lower<upper){
			if(arr[lower]+arr[upper]==sum){
				get.i=lower;
				get.j=upper;
				return get;
				break;
			}else if((arr[lower]+arr[upper])>sum){
				upper--;
			}else{
				lower++;
			}
		}
		
		return get;
	}
}


//main
int main()
{
    //Random function --> unique value generator
    srand(time(0));
    
    int arr[110], i;  //Array size
    unsigned int size = sizeof(arr)/sizeof(arr[0]);

    //STEP-0 Initializing the array
    for(i=0; i<size ; i++){
        arr[i]=-1;
    }
    
    //Null array
    printf("+-------------------------------------------------+\n");
    printf("|                  ASSIGNMENT  1                  |\n");
    printf("+-------------------------------------------------+\n");
    printf("NULL ARRAY OF SIZE %d \n **NOTE : Value -1 is initialized as default and Displayed as NULL \nIf insereted value is -1 then it will be treated as null\n\n",size);
    printf("\n\n[ STEP - 0 : Creating and initializing the array as -1 ]\n");
    display_array(arr,size);
    printf("\n\n");
    
    random_assign(arr,size,100); //Randomly filling array till 100th position
    first_insert(arr,size);
    random_insert(arr,size,102);
    first_delete(arr, size);
	random_delete(arr, size,101);
	
	struct pair search = get_minmax(arr,size,100);
	printf("\n\n[ STEP - 6 : Find minimum and maximum in array from (5) using less than 3n/2 comparisons. ]\n");
	printf("Largest = %d, Smallest = %d \n\n",search.max,search.min);
	
	bubble_sorting(arr,size,100);
	
	struct position value = get_position(arr,100);
	printf("STATUS : i = %d and j = %d .",value.i,value.j);
	
    return 0;
}
