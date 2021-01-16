//Header File
#include<stdio.h>
#include<stdlib.h>

//Binary Tree Structure
struct node{
    int data;
    struct node *left, *right;
};

//Creating the binary Tree
struct node* create(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter the Data = ");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }else{
        newnode->data = x;
        printf("\nFor the left Child of %d \n",x);
        newnode->left = create();
        printf("\nFor the right Child of %d \n",x);
        newnode->right = create();
    }
}

//Main function
int main(){
    struct node *root;
    root = 0;
    printf("Enter the data in Binary Tree");
    printf("Enter -1 to discontinue node");

    root = create();

    printf("Program Ended");
    return 0;
}