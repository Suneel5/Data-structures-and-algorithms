#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node * next;
	
};

void linkedlist_traversal(struct Node *ptr )
{	while(ptr!=NULL){

	printf("Element: %d\n",ptr->data);
	ptr=ptr->next;
}
}
struct Node * insertAtBeginning(struct Node *head,int data){
    //create new  to be added at beginning
    struct Node * newNode=(struct Node *) malloc(sizeof(struct Node));
    newNode->next=head; //point new Node to head
    newNode->data=data;
    return newNode; //return new node as head
}

//Insert new node at paticular given index
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
// Function to insert a new node at the end of the linked list
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

//Insert new node after certain given node
struct Node * insertAfterNode(struct Node * head,struct Node * prevNode,int data){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;

    newNode->next=prevNode->next; //Now New node points to next node to prev node
    prevNode->next=newNode;  //Now previous node points to new node (link breaking)
    return head;

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
	
    printf("Linkedlist before insertion \n");
	linkedlist_traversal(head);
    head=insertAfterNode(head,second,333);
	head=insertAtBeginning(head,25);
    head=insertAtIndex(head,100,2);
    head=insertAtEnd(head,200);
    
    printf("Linkedlist after insertion \n");
    linkedlist_traversal(head);
	return 0;
}
