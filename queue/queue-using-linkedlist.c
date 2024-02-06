#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node *front=NULL;
Node *rear=NULL;

void linkedlist_traversal(){
    printf("\nElement of queue are:\n ");
    Node *ptr=front;
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
	    ptr=ptr->next;
    }
}
int isempty(){
    if(front==NULL) {
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(){
     Node *n=(Node *)malloc(sizeof(Node));
     if(n==NULL){
        return 1;
     }
     else{
        return 0;
     }
}

void enqueue(int val ){
    Node *n=(Node *)malloc(sizeof(Node));
    if(n==NULL){
        printf("queue is Full\n");
    }
    else
    {
        n->data=val;
        n->next=NULL;
        if(front==NULL){ //if queue is empty
            front=rear=n; //front=rear=first element
        }
        else{
            rear->next=n; //link previous last element to new added element
            rear=n;       //Point rear to new added element 
        } 
        // printf("Enqueued element: %d\n",val);
    }
}

int dequeue(){ //only front pointer required
    int val=-1;
    if(front==NULL){
        printf("queue is Empty\n");
    }
    else{
        Node *ptr=front;
        val=ptr->data;
        front=front->next;
        free(ptr);
        return val;
    }
}
int main(){
    linkedlist_traversal();
    //inserting element to queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);

    linkedlist_traversal();

    //removing element form queue
    printf("%d removed from queue\n",dequeue());
    printf("%d removed from queue\n",dequeue());
    printf("%d removed from queue\n",dequeue());
    printf("%d removed from queue\n",dequeue());
    printf("%d removed from queue\n",dequeue());

    linkedlist_traversal();
    return 0;
}