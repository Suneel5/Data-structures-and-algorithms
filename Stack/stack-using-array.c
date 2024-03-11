#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int size;
    int top;  #index of top element
    int *arr;
}stack;

int isempty(stack *sp){
    if (sp->top==-1)  //top of empty stack is -1
    {
        return 1;
    }
    return 0;   
}

int isfull(stack *sp){
    if(sp->top==sp->size-1){
        return 1;
    }
    return 0;
}

//push value to stack at top
void push(stack *sp, int value){
    if (isfull(sp)){
        printf("Stack Overflow , Cant push %d\n", value);
    }
    else{
        sp->top++;     
        sp->arr[sp->top]=value;  //push value in  new incremented top vlaue
    }
}

//remove top element of stack
int  pop(stack *sp){
    if (isempty(sp)){
        printf("Stack underflow \n");
        return -1;
    }
    else{
        return sp->arr[sp->top--];
    }
}

//return data at given position, position starts from top ie pos =1 for top value
int peek(stack *sp,int pos,int *arr_index){
    *arr_index=sp->top-pos+1;
    if (*arr_index<0){
        printf("Not valid position for the stack\n");
    }
    else{
        return sp->arr[*arr_index];
    }
}

//returns top value of stack 
int stackTop(stack *sp){
    return sp->arr[sp->top];
}

//return bottom value of stack 
int stackBottom(stack *sp){
    return sp->arr[0];
}


int main(){
    int value,arr_index;
    stack *sp=(stack *)malloc(sizeof(stack));;
    sp->size=MAX_SIZE;
    sp->top=-1;
    sp->arr=malloc(sp->size*sizeof(int));
    printf("Stack created\n");
    if(isempty(sp))
    {
        printf("Stack is empty \n");
    }
    else{
        printf("Stack is not empty \n");
    }

    push(sp,10);
    push(sp,20);
    push(sp,30);
    push(sp,40); 
    push(sp,50);   
    push(sp,60);
    push(sp,70);
    push(sp,80);
    push(sp,90);

    if (isfull(sp)){
        printf("Stack is full \n");
    }
    else
    {
        printf("Stack not full \n");
    }

    printf("popped %d from stack \n",pop(sp));

    //printing values from the stack
    for (int i=1; i<=sp->top+1; i++){

        printf("Value at position %d (array index %d)is %d \n",i,arr_index,peek(sp,i,&arr_index));
    }
    return 1;
}
