#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node * next;
	
};

void linkedlist_traversal(struct Node *ptr )
{	while(ptr!=NULL){

	printf("Element: %d\n",ptr->data);
	ptr=ptr->next;
}
}

//Case 1 :Insert node at beginning of linkedlist
struct Node * insertAtBeginning(struct Node *head,int data){
    //create new  to be added at beginning
    struct Node * newNode=(struct Node *) malloc(sizeof(struct Node));
    newNode->next=head; //point new Node to head
    newNode->data=data;
    return newNode; //return new node as new head
}

// Case 2 Insert new node at paticular given index
struct Node * insertAtIndex(struct Node *head,int data,int index){
    struct Node * newNode = malloc(sizeof(struct Node));  //node to be added at index  pos
    struct Node * p =head;   
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    } 
    //Now p in the node at index-1 pos
    newNode->data = data;
    newNode->next=p->next;  //new node points to node at index pos
    p->next=newNode;       //index-1 node points to new node
    return head;
}
//Case 3 Function to insert a new node at the end of the linked list
struct Node * insertAtEnd(struct Node* head, int data){
    //create new node to be added at end
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    struct Node* p =head; // node that  points to head
    
    while(p->next !=NULL){
        p=p->next; //traversing nodes to find last node
    }
    //now p is last node 
    p->next=newNode; //now new node becomes last node of LL
    newNode->next=NULL;
    return head;
}

//Case 4 Insert new node after certain given node
struct Node * insertAfterNode(struct Node * head,struct Node * prevNode,int data){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=prevNode->next; //Now New node points to next node to prev node
    prevNode->next=newNode;  //Now previous node points to new node (link breaking)
    return head;

}

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

int main(){	
	// Create an empty linked list
    struct Node* head = NULL;

    //Insert Nodes
	head=insertAtBeginning(head,90);
	head=insertAtBeginning(head,80);
	head=insertAtBeginning(head,50);
    head=insertAtIndex(head,60,1);
    head=insertAtIndex(head,70,2);
    head=insertAtEnd(head,100);
    head=insertAtEnd(head,110);
    printf("Linked list after insertion:\n");
    linkedlist_traversal(head);

    //Delete nodes
    head=deleteFirstNode(head);
    head=deleteAtIndex(head,0);
    head=deleteAtIndex(head,2);
    head=deleteLastNode(head);
    head=deleteAtValue(head,100);
    printf("Linkedlist after deletion \n");
    linkedlist_traversal(head);
	return 0;
}
