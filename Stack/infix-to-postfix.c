#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
typedef struct stack {
    int top;
    int size;
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
char stackTop(stack *sp){
    return sp->arr[sp->top];
}
int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    return 0;
}

int isOperator(char ch){
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return 0;
    }
}


//infix exp to postfix exp using stack
char * infixToPostfix(char *infix){
    stack * sp=(stack *)malloc(sizeof(stack));
    sp->size=MAX_SIZE;
    sp->top=-1;
    sp->arr=(char *) malloc(sp->size*sizeof(char));
    char * postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0; //Track infix traversal
    int j=0; //Track postfix addition
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i])) //ie char at i position is operand(ie not operator)
        {
            postfix[j]=infix[i];  //add that char to postfix exp 
            i++;
            j++;
        }
        else
        {
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp,infix[i]);    //if precedence of operator is greater than op at 
                                     //top of stack then push that operator to stack   
                i++;                 
            }
            else {
                postfix[j]=pop(sp);   //if precedence of operator is lower or equal to op at
                                     //top of stack then add that op at top of stack to postfix exp
                j++;                 //i is not incremented here to compare with new operator at top pos
            }

        }
    }
    while(!isempty(sp))
    {
        postfix[j]=pop(sp);    //pop operator which are in stack till stack becomes empty after infix exp is scanned competely
        j++;
    }
    postfix[j]='\0';  
    return postfix;
}

int main(){
    char *infix="p-q-r/a";
    //postfix=pq-ra/-
    printf("Postfix is : %s\n",infixToPostfix(infix));
    return 0;
}