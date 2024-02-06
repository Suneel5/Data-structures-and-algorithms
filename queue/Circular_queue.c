#include<stdio.h>
#include<stdlib.h>

typedef struct cir_queue{
    int size;
    int *arr;
    int rear_i;
    int front_i;
}cir_queue;

//full when cir inc to last element is equal to index of front element
int isfull(cir_queue *q){
    if((q->rear_i+1)%q->size==q->front_i){  //
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(cir_queue * q){
    if(q->front_i==q->rear_i){
        return 1;
    }
    else{
        return 0;
    }
}
// circular increment rear_i and instert at rear_i
void enqueue(cir_queue *q,int val){
    if (isfull(q)){
        printf("queue overflow\n");
    }
    else{
        q->rear_i=(q->rear_i+1)%q->size;
        q->arr[q->rear_i]=val;
        printf("Enqueued element: %d\n",val);
    }
}

//circular increment front_i and remove element at front_i
int dequeue(cir_queue *q){
    int val;
    if(isempty(q)){
        printf("Queue empty\n");
    }
    else{
        q->front_i=(q->front_i+1)%q->size;
        val= q->arr[q->front_i];
        return val;
    }
}

int main(){
     int val;
    cir_queue * q=(cir_queue *)malloc(sizeof(cir_queue));
    q->size=5;
    q->front_i=0;
    q->rear_i=0;
    q->arr=(int *)malloc(sizeof(int)*q->size);

    //insert elements form back
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);

    //remove element form front
   
    val=dequeue(q);
    printf("%d removed form queue\n",val);
    
    val=dequeue(q);
    printf("%d removed form queue\n",val);

    val=dequeue(q);
    printf("%d removed form queue\n",val);

    val=dequeue(q);
    printf("%d removed form queue\n",val);

    enqueue(q,100);


    
}