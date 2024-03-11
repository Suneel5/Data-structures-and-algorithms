// Implementing a stack using a linked list involves creating a data structure that
// mimics the behavior of a stack, where elements are added and removed from one end
// (the top). In a linked list-based implementation,  dynamically allocate nodes
// to store the stack elements, and each node points to the next node in the stack.
// top element is head
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

int isempty(node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(node *top){
    node* n=(node *)malloc(sizeof(node));
    if (n==NULL){  //ie cant allocate memory for n
        return 1;
    }
    else{
        return 0;
    }
}
void stackTraversal(node *top)
{
    node* n=top;
    while(n!=NULL){
        printf("Element: %d\n",n->data);
        n=n->next;
    }
}

//func to push new node before top
node * push(node *top,int x){
    if(isfull(top)){
        printf("Stack overflow \n");
    }
    else{
        node* newNode=(node *)malloc(sizeof(node));
        newNode->data=x;
        newNode->next=top;  //pointing new node to top(to making top second node)
        top=newNode;  //making new node as  new top
    }
    return top;
}

//func to remove top element
int pop(node ** top){   
    if (isempty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        int data;
        node* n =*top;
        *top=(*top)->next;  //making second node as top(as first node needs to be pop)
        data=n->data;
        free(n);     //deallocating memory of first node(previous top)
        return data;
    }
}
int peek(node * top,int pos){
    node* n = top;

    for(int i=0;(i<pos-1&&n!=NULL);i++){ 
        n=n->next;
    }
    //now n is the node at position=pos
    if(n!=NULL){
        return n->data;
    }
    return -1;
}

int stackTop(node * top){
    return top->data;
}

int stackBottom(node * top){
    node* n =top;
    while(n->next != NULL){
        n=n->next;
    }
    //now n is last node
    return n->data;


}
int main(){
    int data;
    node* top=NULL;
    data=pop(&top);

    top=push(top,10);
    top=push(top,20);
    top=push(top,30);
    top=push(top,40);
    top=push(top,50);
    top=push(top,60);
    top=push(top,70);
    top=push(top,80);
    top=push(top,90);
    top=push(top,100);
    printf("Stack after pusing: \n");
    stackTraversal(top);
 
    printf("Poped element: %d\n",pop(&top));
    printf("Poped element: %d\n",pop(&top));
    printf("Element after popping: \n");
    stackTraversal(top);
    int i=2;
    printf("Element at pos %d is %d\n",i,peek(top,i));
    printf("Top Element: %d\n",stackTop(top));
    printf("Bottom Element: %d\n",stackBottom(top));
    return 1;
}