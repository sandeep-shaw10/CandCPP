//Importing pre-defined file
#include<stdio.h>
#include<stdlib.h>

//Creating a structure of Node
struct Node {
    int data;
    struct Node* next;
}Node;

//Storing address of the head and tail [global variable]
struct Node* head;
struct Node* tail;

void addFront(int value)
{
    struct Node* head_ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail_ptr = (struct Node*)malloc(sizeof(struct Node));  
	  
    head_ptr->data = value;
    head_ptr->next = head;
    
    //Storing pointer for tail addLast
    if(tail == NULL){
    	tail_ptr->data = value;
    	tail_ptr->next = tail;
    	tail = tail_ptr;
	}
	
    head = head_ptr;
}

void printList()
{
	struct Node* temp_head = head;
	while(temp_head != NULL){
		printf("%d ",temp_head->data);
		temp_head = temp_head->next;
	}
	printf("\n");
	
	struct Node* temp_tail = tail;
	while(temp_tail != NULL){
		printf("%d ",temp_tail->data);
		temp_tail = temp_tail->next;
	}
	printf("\n");
	
}

void addLast(int value){
	struct Node* tail_ptr = (struct Node*)malloc(sizeof(struct Node));	
	if (tail == NULL){
		addFront(value);
	}
	tail->next = tail_ptr;
	tail_ptr->data = value;
	tail_ptr->next = NULL;
	
}

int main()
{
	head = NULL;
	tail = NULL;
	
    int i,n,x;
    printf("ENTER THE TOTAL NUMBER YOU WANT TO INSERT IN THE LIST : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nENTER THE NUMBER : ");
        scanf("%d",&x);
        
        printf("List : ");
        addFront(x);
        printList();
    }
    
	addLast(100);
	addLast(1000);
	printList();
	
    return 0;
}

