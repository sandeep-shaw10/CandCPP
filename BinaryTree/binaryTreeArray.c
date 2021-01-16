//Header File
#include<stdio.h>
#define MAX 100

//Array representation of binary complete tree
//nth Child --- Left Child == 2n+1 
//nth Child --- Right Child == 2n+2
//Parent  ===== LowerBound[(i-1)/2]


//Main function
int main(){
    int tree[MAX];
    int i, nodes, parent;
    printf("End the no. of nodes in array = ");
    scanf("%d",&nodes);
    
    
    //Accepting Tree in form of Array
    for (int i = 0; i < nodes; i++) {
        if(i==0){
            printf("Enter the root node = ");
            scanf("%d",&tree[i]);
            printf("============================================\n");
        }else{
            parent = (i-1)/2;
            parent = tree[parent];
            if(i%2==0){
                printf("Enter the right child node for %d = ",parent);
                scanf("%d",&tree[i]);
            }else{
                printf(" Enter the left child node for %d = ",parent);
                scanf("%d",&tree[i]);
            }

        }
    }
    
    //Printing the Array
    printf("\nPre-order Traversal : ");
    for (int i = 0; i < nodes; i++) {
        printf("%d ",tree[i]);
    }
    
}