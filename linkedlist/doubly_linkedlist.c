#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void doubly_ll_traverse(struct Node *head){
    struct Node *p=head;
    printf("Elements when traversing from head to tail: \n");

   while(p->next!= NULL){
        printf("Element: %d \n", p->data);
        p=p->next;
    }
    //Now p is the last node;
    printf("Element: %d \n", p->data);
    printf("Elements when traversing from tail to head: \n");

    while(p!=NULL){
    printf("Element: %d \n", p->data);
    p=p->prev;

    }
}


int main()
{
    //create nodes
    struct Node *N1=(struct Node*)malloc(sizeof(struct Node));
    struct Node *N2=(struct Node*)malloc(sizeof(struct Node));
    struct Node *N3=(struct Node*)malloc(sizeof(struct Node));
    struct Node *N4=(struct Node*)malloc(sizeof(struct Node));

    //link nodes
    N1->prev=NULL;
    N1->next=N2;
    N2->prev=N1;
    N2->next=N3;
    N3->prev=N2;
    N3->next=N4;
    N4->prev=N3;
    N4->next=NULL;

    //set data
    N1->data=10;
    N2->data=20;
    N3->data=30;
    N4->data=40;
    
    doubly_ll_traverse(N1);
    return 0;
}