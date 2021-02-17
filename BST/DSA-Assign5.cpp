#include <bits/stdc++.h>
using namespace std;


//Binary Search Tree Structure
struct Node {
    int key;
    struct Node *left, *right;
};


//Creating a new node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


// Inserting the node
Node* insert(Node* root, int key)
{ 
    Node* newnode = newNode(key);
    Node* x = root;     //Pointing root node
    Node* y = NULL;     //Pointing to NULL
    while (x != NULL) {     //If tree is not empty
        y = x;
        if (key < x->key)
            x = x->left;    //If value is less than node move to Left Child
        else
            x = x->right;   //If value is more than node move to Right Child
    }
    if (y == NULL){
        y = newnode;        //If y is NULL, tree empty -> make this as rootnode
    }else if (key < y->key){
        y->left = newnode;  //If inserted key is less than node key -> Place left Child 
    }else{
        y->right = newnode; //If inserted key is more than node key -> Place right Child
    }
    return y;
}


//Height of Tree
int Height(Node* node) 
{ 
    if (node == NULL) 
        return -1; 
    else
    { 
        int lDepth = Height(node->left);    //compute the depth of Left subtree
        int rDepth = Height(node->right);   //compute the depth of Right subtree

        if (lDepth > rDepth)                //Comparing both subtree recursively
            return(lDepth + 1); 
        else 
            return(rDepth + 1); 
    } 
}


//Inorder Traversal
void InorderTraversal(Node* root)
{
    if (root == NULL)
        return;     //For empty tree return null
    else {
        InorderTraversal(root->left);   //Left
        cout << root->key << " ";       //Node
        InorderTraversal(root->right);  //Right
    }
}


//Search the node in binary search Tree
struct Node* search(struct Node* root, int key)
{ 
    if (root == NULL || root->key == key)   //If root is null or key is present at root
       return root;
    
    if (root->key < key)                    // Key is greater than root's key
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

//Inorder Successor
void inorderSuccessor(Node* root, Node* target_node, Node* &next) 
{ 
    if(!root)           // if root is null then return 
        return; 
  
    inorderSuccessor(root->right, target_node, next);  
    // if target node found then enter this condition 
    if(root->key == target_node->key) 
    { 
        // this will be true to the last node 
        // in inorder traversal i.e., rightmost node. 
        if(next == NULL) 
            cout << "Inorder successor of " << root->key << " is: null\n"; 
        else
            cout << "Inorder successor of " << root->key << " is: " << next->key << "\n";  
    } 
    next = root; 
    inorderSuccessor(root->left, target_node, next); 
}

//Deleting Node
Node* deleteNode(Node* root, int k)
{
    if (root == NULL)       //Empty tree
        return root;
    if (root->key > k) {        // Recursive calls for ancestors of node to be deleted
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->key < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
    if (root->left == NULL) {       // If one of the children is empty
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    else {  // If both children exist
        Node* succParent = root;
        Node* succ = root->right;   // Find successor
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->key = succ->key;  // Copy Successor Data to root
        delete succ;    // Delete Successor and return root
        return root;
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Creating a new node
    Node* root = NULL;

    //Insert the values 30, 45, 20, 10, 60, 56, 39, 41, 63, 5 in a binary search tree
    root = insert(root, 30);
    insert(root, 45);
    insert(root, 20);
    insert(root, 10);
    insert(root, 60);
    insert(root, 56);
    insert(root, 39);
    insert(root, 41);
    insert(root, 63);
    insert(root, 5);

    //Find the height of your tree
    int h = Height(root);
    cout << "Height of tree : " << h << "\n";

    //In-Order Traversal
    cout << "In-Order Traversal : ";
    InorderTraversal(root);

    //Find the location of the node 
    Node* a1 = search(root,56);
    Node* a2 = search(root,10);

    //Find the in-order successor of 56 and 10
    Node* next = NULL;
    cout << "\n";
    inorderSuccessor(root, a1, next);
    inorderSuccessor(root, a2, next);

    //Delete the value 30 from the tree
    root = deleteNode(root, 30);
    cout << "In-Order Traversal after deleting 30 : ";
    InorderTraversal(root);

    return 0;
}
