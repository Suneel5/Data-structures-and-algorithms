#include<stdio.h>
#include<stdlib.h>

//queue follows FIFO Fashion
typedef struct queue{
    int size;
    int *arr;
    int rear_i;
    int front_i;
}queue;

int isfull(queue *q){
    if(q->rear_i==q->size-1){  //index of last element = size-1
        return 1;
    }
    else{
        return 0;
    }
}
//Front_i is not equal to the index of the first element to facilitate easy detection of an empty queue.
int isempty(queue * q){
    if(q->rear_i==q->front_i){ 
        return 1;
    }
    else{
        return 0;
    }
}

//increment rear_i and instert at rear_i
void enqueue(queue* q,int val){
    if (isfull(q)){
        printf("Queue Overflow\n");
    }
    else{
        q->rear_i+=1;
        q->arr[q->rear_i]=val;
    }
}

//increment front_i and remove element at front_i
int dequeue(queue* q){
    int a=-1;
    if(isempty(q)){
        printf("Queue Empty\n");
        return a;
    }
    else{
        q->front_i+=1;
        a=q->arr[q->front_i];
        return a;
    }
}
int firstVal(queue* q){
    if(isempty(q))
    {
        printf("Queue Empty\n");
        return -1;
    }
    else
    {
    return q->arr[q->front_i+1];
    }
}
int lastVal(queue* q){
    if(isempty(q)){
        printf("Queue Empty\n");
        return -1;
    }
    else{
        return q->arr[q->rear_i];
    }
}
int main(){
    queue * q=(queue *)malloc(sizeof(queue));
    q->size=10;
    q->front_i=-1;
    q->rear_i=-1;
    q->arr=(int *)malloc(sizeof(int)*q->size);

    //insert elements form back
    printf("First value= %d\n",firstVal(q));
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);

    //remove element form front
    int val;
    val=dequeue(q);
    printf("%d removed form queue\n",val);
    
    val=dequeue(q);
    printf("%d removed form queue\n",val);

    printf("After dequeing\n");
    printf("First value= %d\n",firstVal(q));
    printf("last value= %d\n",lastVal(q));

    
}