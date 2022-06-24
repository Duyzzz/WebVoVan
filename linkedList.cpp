#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
typedef struct Node NODE;

struct list {
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

void initialization (LIST &ds){
    ds.pHead = NULL;
    ds.pTail = NULL;
}

int checkForEmpty (LIST ds) {
    if(ds.pHead == NULL){
        return 1;
    }
    return 0;
}

NODE *newNode (int x){
    NODE *p;
    p = new NODE;
    if (p == NULL)
    {
        printf("Not enough memory");
        return NULL;
    }
    p -> data = x;
    p -> next = NULL;
    return p;

}
LIST inputArray(unsigned int numberOfArray){
    LIST ds;
    int tempElement;
    initialization(ds);
    NODE *p;
    p = newNode(0);
    ds.pHead = p;
    cout << "Element " << 0 << " is ";
    cin >> tempElement;
    p -> data = tempElement;
    for(unsigned int i = 1; i < numberOfArray; i++){
        cout << "Element " << i << " is ";
        cin >> tempElement;
        p -> next = newNode(tempElement);
        p = p -> next;
    }
    p -> next = newNode(0);
    return ds;
}
void printArray(LIST array){
    NODE *p;
    p = array.pHead;
    int i = 0;
    cout << endl;
    while(p -> next != NULL){
        cout << p -> data << " ";
        p = p -> next;
        i++;
    }
}
int main(){
    LIST ds;
    unsigned int numberOfArray;
    cout << "Please enter the number of the array" << endl;
    cin >> numberOfArray;
    ds = inputArray(numberOfArray);
    printArray(ds);
    return 0;
}