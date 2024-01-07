#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node * next;
};

void circular_ll_traversal(struct Node *head){
    struct Node *p=head;
    do{
        printf("Element: %d \n", p->data);
        p=p->next;
    }while(p!=head);
}

struct Node * insertAtbeginning(struct Node *head,int data){
	struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));	
	struct Node *p=head;

	newNode->data=data;
	newNode->next=head;   //pointing new node to head
	while(p->next!=head)
	{
		p=p->next;
	}   
	//now p is last node
	p->next=newNode;  //pointing last node to new node
	head=newNode; //now new node is head
	return head;

}

int main()
{
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
	head->data=4;
	head->next=second;
	
	//link second  and third nodes
	second->data=3;
	second->next=third;
	
    // link third and fourth nodes
    third->data=2;
    third->next=fourth;

	//terminate the list at the fourth node
	fourth->data=1;
	fourth->next=head;  //pointing last node to head
	printf("Circular Linkded list before insertion:\n ");
    circular_ll_traversal(head);
	head=insertAtbeginning(head,200);
	head=insertAtbeginning(head,100);
	printf("Circular Linkded list after insertion:\n ");
	circular_ll_traversal(head);
    return 0;
}
