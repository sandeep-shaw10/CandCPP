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

void addFront(int value){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = head;
	if(head==NULL){
    	temp->data = value;
    	temp->next = tail;
    	tail = temp;
	}
    head = temp;
}


void addLast(int value){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if(head==NULL){
    	head=temp;
    	tail=temp;
	}else{
		tail->next = temp;
		tail = temp;
	}
}


void deleteFront(){
    struct Node* temp;
    if(head==NULL){
        printf("UNDERFLOW");
    }else{
        temp = head;
        head = temp->next;
        free(temp);
    }  
}

void deleteLast(){
    struct Node* temp=head;
    if(head==NULL){
        printf("UNDERFLOW");
    }else if(head->next==NULL){
        head = NULL;
        tail = NULL;
    }else{
        while (temp->next->next != NULL) 
        temp = temp->next; 
      
        // Delete last node 
        free(temp->next); 
      
        // Change next of second last 
        temp->next = NULL; 
    }
}


void printList(){
    
	struct Node* temp_head = head;
	if(head==NULL){
	    printf("LIST IS EMPTY !");
	    return;
	}
	while(temp_head != NULL){
		printf("%d ",temp_head->data);
		temp_head = temp_head->next;
	}
	printf("\n");	
}


int main(){
	head = NULL;
	tail = NULL;
	
    int i,n,x;
    
    //Inserting at the beginning
    printf("ENTER THE TOTAL NUMBER YOU WANT TO INSERT IN THE LIST [ AT THE BEGINNING ]: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nENTER THE NUMBER : ");
        scanf("%d",&x);
        
        printf("List : ");
        addFront(x);
        printList();
    }
    
    //Inserting at the end
    printf("\n\nENTER THE TOTAL NUMBER YOU WANT TO INSERT IN THE LIST [ AT THE LAST ]: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nENTER THE NUMBER : ");
        scanf("%d",&x);
        
        printf("List : ");
        addLast(x);
        printList();
    }
    
    //Deleting from the beginning
    int flag = 1;
    while(flag){
        printf("\nENTER `1` TO DELETE FROM THE BEGINNING AND `0` TO EXIT. ");
        scanf("%d",&flag);
        if(flag==1){
            deleteFront();
            printList();
        }
    }
    
    //Deleting from the Last
    flag = 1;
    while(flag){
        printf("\nENTER `1` TO DELETE FROM THE END AND `0` TO EXIT. ");
        scanf("%d",&flag);
        if(flag==1){
            deleteLast();
            printList();
        }
    }
    
    return 0;
}

