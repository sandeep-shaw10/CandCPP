/* Program to insert in a sorted list */
#include <stdio.h> 
#include <stdlib.h> 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 


void sortedInsert(struct Node** head_ref,struct Node* new_node) { 
	struct Node* current; 
	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data) { 
		new_node->next = *head_ref; 
		*head_ref = new_node; 
	} 
	else { 
		current = *head_ref; 
		while (current->next != NULL && current->next->data < new_node->data) { 
			current = current->next; 
		} 
		new_node->next = current->next; 
		current->next = new_node; 
	} 
} 


struct Node* newNode(int new_data) { 
	/* allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 
	new_node->next = NULL; 

	return new_node; 
} 

/* Function to print linked list */
void printList(struct Node* head) { 
	struct Node* temp = head; 
	while (temp != NULL) { 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
} 

/* Driver program to test count function*/
int main() { 
	/* Start with the empty list */
	struct Node* head = NULL; 
	struct Node* new_node = newNode(5);
	int i,n,x;
    
    //Inserting at the beginning
    printf("ENTER THE TOTAL NUMBER YOU WANT TO INSERT IN THE LIST [ AT THE BEGINNING ]: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nENTER THE NUMBER : ");
        scanf("%d",&x);
        
		new_node = newNode(x); 
		sortedInsert(&head, new_node);
		
		printf("List : ");
        printList(head);
    }

	return 0; 
} 

