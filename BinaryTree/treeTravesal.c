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

//Pre-order Tree Traversal
void preorder(struct node *root){
    if(root==0){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

//In-order Tree Traversal
void inorder(struct node *root){
    if(root==0){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

//Post-order Tree Traversal
void postorder(struct node *root){
    if(root==0){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

//Main function
int main(){
    struct node *root;
    root = 0;
    printf("Enter the data in Binary Tree\n");
    printf("Enter -1 to discontinue node\n========================================\n");

    root = create();
    
    printf("\nPRE-ORDER TRAVERSAL\n");
    preorder(root);
    
    printf("\nIN-ORDER TRAVERSAL\n");
    inorder(root);
    
    printf("\nPOST-ORDER TRAVERSAL\n");
    postorder(root);

    printf("\nProgram Ended");
    return 0;
}