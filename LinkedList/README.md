# Linked List in C++

> Singly Linked List allOperations

```cpp
#include<iostream>
using namespace std;

// Singly Linked List Data Structure
class Node{
    public:
        int data;
        Node* next;
};

int getSize(Node* head){
    int count = 0;
    while(head != NULL){ head=head->next; count++; }
    return count;
}

void pushFront(Node** headPtr, Node** tailPtr, int newData){
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*headPtr);
    
    if((*headPtr) == NULL){ (*tailPtr) = newNode; }

    (*headPtr) = newNode;
}

void pushBack(Node** headPtr, Node** tailPtr, int newData){
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if((*headPtr) == NULL){
        (*headPtr) = (*tailPtr) = newNode; 
    }
    else{
        (*tailPtr)->next = newNode;
        (*tailPtr) = newNode;
        (*tailPtr)->next = NULL;
    }
    
}

void pushAfter(Node** headPtr, Node** tailPtr, int value, int position){
    //Position index starts from 0
    int size = getSize((*headPtr))-1;

    if( size >= position){
        if(headPtr == NULL || position == 0) { pushFront(&(*headPtr), &(*tailPtr), value); }
        else if(position == size) { pushBack(&(*headPtr), &(*tailPtr), value); }
        else{
            Node* temp = new Node();
            temp = (*headPtr);

            for(int i=0; i<position; i++){ temp = temp->next; }

            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }else{
        cout << "Not Possible! Size Limit Exceed" << endl;
    }
}

void displayList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n" << endl;
}

void deleteFront(Node** head, Node** tail){
    if((*head) == NULL){
        cout << "UNDERFLOW" << endl;
    }else if((*head) == (*tail)){
        (*head) = NULL;
        (*tail) = NULL;
    }else{
        Node* temp = new Node();
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    }
}

void deleteLast(Node** head, Node** tail){
    if((*tail) == NULL){
        cout << "UNDERFLOW" << endl;
    }else if((*head) == (*tail)){
        (*head) = NULL;
        (*tail) = NULL;
    }else{

        Node* temp = new Node();
        temp = (*head);
        while(temp->next != (*tail)){
            temp = temp->next;
        }
        (*tail) = temp;
        (*tail)->next = NULL;
        temp = temp->next;

        free(temp);
    }
}

void deleteAt(Node** headPtr, Node** tailPtr, int position){
    int size = getSize((*headPtr))-1;
    if((*headPtr) == NULL){
        cout << "UNDERFLOW" << endl;
    }
    else{
        if(size >= position){
            if(position==0) { deleteFront(&(*headPtr), &(*tailPtr)); }
            else if(position==size) { deleteLast(&(*headPtr), &(*tailPtr)); }
            else{
                Node* temp = new Node();
                Node* tempCache = new Node();
                temp = (*headPtr);
                for(int i=1; i<position; i++){ temp=temp->next; }
                temp->next = temp->next->next;
                
            }
        }
    }

}

bool floydCycle(Node* head){
    bool cycle = false;
    Node* slow = new Node();
    Node* fast = new Node();
    slow = fast = head;

    while(fast->next == NULL || fast->next->next == NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){ 
            cycle = true;
            break;
        }
    }

    return cycle;
}

Node* getMiddle(Node* first, Node* last) {
    Node *slow = first;
    Node *fast = first;
    while(fast != last && fast != last->next && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* getMiddleStrict(Node* first, Node* last) {
    if(first == last){ return NULL; }
    Node *slow = first;
    Node *fast = first;
    while(fast != last && fast != last->next && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool linearSearch(Node* headPtr, int key){
    bool found = false;

    while(headPtr != NULL){
        if(headPtr->data == key){
            found = true;
            break;
        }
        headPtr = headPtr->next;
    }

    return found;
}

bool binarySearch(Node* headPtr, Node* tailPtr, int key){
    Node* left = headPtr;
    Node* right = tailPtr;
    bool found = false;

    Node* mid = getMiddleStrict(left, right);

    while(left != right || right==NULL){

        if(mid == NULL){ break; }

        if(mid->data == key){ found=true; break; }

        else if(mid->data < key){ left = mid; }
        
        else{ right = mid->next; }

        mid = getMiddleStrict(left, right);
    }

    return found;
}

void updateAt(Node* headPtr, int value, int position){
    while(position > 0 && headPtr != NULL){
        headPtr = headPtr->next;
        position--;
    }

    if(position == 0){ headPtr->data = value; }
    else{ cout << "List Out of Bound " << endl;}
}

void reverseList(Node** headPtr, Node** tailPtr){
    Node* prev = NULL;
    Node* next = NULL;
    Node* current = (*headPtr);

    while(current != NULL){
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    (*tailPtr) = (*headPtr);
    (*headPtr) = prev;
}

Node* SortedMerge(Node* a, Node* b){
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef){
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void mergeSort(Node** headPtr){

    Node* head = *headPtr;
    Node* a;
    Node* b;
 
    if ((head == NULL) || (head->next == NULL)) {
        return; /* Base case -- length 0 or 1 */
    }
 
    FrontBackSplit(head, &a, &b);   /* Split head into 'a' and 'b' sublists */
 
    mergeSort(&a);
    mergeSort(&b);
 
    *headPtr = SortedMerge(a, b);   /* answer = merge the two sorted lists together */
}

void sort(Node** headPtr, Node** tailPtr){
    mergeSort(&(*headPtr));
    Node* temp = (*headPtr);

    while(temp->next != NULL){
        temp = temp->next;
    }

    (*tailPtr) = temp;
}

int main(){

    Node* headPtr = new Node();
    Node* tailPtr = new Node();
    headPtr = tailPtr = NULL;

    pushFront(&headPtr, &tailPtr, 1);
    pushBack(&headPtr, &tailPtr, 2);
    pushBack(&headPtr, &tailPtr, 3);
    pushBack(&headPtr, &tailPtr, 5);
    pushBack(&headPtr, &tailPtr, 8);
    pushAfter(&headPtr, &tailPtr, 85, 3);
    displayList(headPtr);

    updateAt(headPtr, 98908, 3);
    displayList(headPtr);

    reverseList(&headPtr, &tailPtr);
    displayList(headPtr);

    sort(&headPtr, &tailPtr);
    displayList(headPtr);
    cout << tailPtr->data << endl;

    return 0;
}
```
