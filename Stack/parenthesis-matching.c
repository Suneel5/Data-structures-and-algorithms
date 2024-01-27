#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

typedef struct stack{
    int size;
    int top;
    char *arr;
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

//push char value to stack at top
void push(stack *sp, char value){
    if (isfull(sp)){
        printf("Stack Overflow , Cant push %d\n", value);
    }
    else{
        sp->top++;     
        sp->arr[sp->top]=value;  //push value in  new incremented top vlaue
    }
}

//remove top char element of stack
char  pop(stack *sp){
    if (isempty(sp)){
        printf("Stack underflow \n");
        return -1;
    }
    else{
        return sp->arr[sp->top--];
    }
}
//using stack To check if parentheses are balanced in an expression
int parentheses_matching(char * exp){
    stack * sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size *sizeof(char));

    for (int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            //push if ( if found in exp
            push(sp,exp[i]);
        }
        else if(exp[i]==')'){
            //pop if ) is found in exp
            if(isempty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    //if exp is balenced then stack becomes empty after end of exp
    if (isempty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char * expression="((3+4)*7)/5)";
    if (parentheses_matching(expression)){
        printf("The parentheses is matching");
    }
    else{
        printf("The parentheses is not matching");
    }
}