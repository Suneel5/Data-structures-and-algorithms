#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node * next;
	
};

//case 1: Deleting first node/element(head)
struct Node * deleteFirstNode(struct Node *head){
    struct Node *ptr=head;
    head=head->next; //second node becomes head
    free(ptr);       
    return head;

}

//case 2 :Deleting the element at given index
struct Node * deleteAtIndex(struct Node *head, int index){
    struct Node * p=head;
    struct Node * q=head->next;
    if(index==0){
        head=deleteFirstNode(head);
        return head;
    }
    else
    {
        for(int i=0; i<index-1;i++){
            p=p->next;
            q=q->next;
        }
        //Now p contains node at index-1
        //Now q is the node/element to be deleted
        p->next=q->next;
        free(q);
        return head;
    }
}

//Case 3 : delete last node
struct Node * deleteLastNode(struct Node *head)
{
    struct Node * p=head;
    struct Node * q=head->next;

    while(q->next !=NULL){
        p=p->next;
        q=q->next;
    }
    //Now q is the last node  and p is previous node of last node

    p->next=NULL;
    free(q);
    return head;

}
//case 4 :Deleting the element with given value
struct Node * deleteAtValue(struct Node *head, int value){
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    //Now q(value) is the node/element to be deleted 
    //p is previous node to q

    if(q->data==value){
        p->next=q->next;
        free(q);
        }
    return head;  
}


void linkedlist_traversal(struct Node *ptr )
{	while(ptr!=NULL){

	printf("Element: %d\n",ptr->data);
	ptr=ptr->next;
}
}

int main(){
	struct Node * head;
	struct Node * second;
	struct Node * third;
    struct Node * fourth;
	
	// Allocate memory for nodes in the linked list in heap
	head=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
	
	//link first and second nodes
	head->data=7;
	head->next=second;
	
	//link second  and third nodes
	second->data=11;
	second->next=third;
	
    // link third and fourth nodes
    third->data=54;
    third->next=fourth;

	//terminate the list at the fourth node
	fourth->data=66;
	fourth->next=NULL;
	
    printf("Linkedlist before deletion \n");
	linkedlist_traversal(head);

    // head=deleteFirstNode(head);
    head=deleteAtIndex(head,0);
    head=deleteLastNode(head);
    head=deleteAtValue(head,54);
    printf("Linkedlist after deletion \n");
    linkedlist_traversal(head);

}