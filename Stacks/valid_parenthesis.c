#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>
struct Stack{
    char arr[10000];
    int top;
};

bool isFull(struct Stack *stack,int size){
    if(stack->top == size-1){
        return true;
    }
    return false;
}

bool isEmpty(struct Stack *stack){
    if(stack->top==-1){
        return true;
    }
    return false;
}

void push(struct Stack *stack,char element,int size){
    if(isFull(stack,size)){
        return;
    }
    stack->top++;
    stack->arr[stack->top] = element;
}

void pop(struct Stack *stack,int size){
    if(isEmpty(stack)){
        return;
    }
    stack->top--;
}

char peek(struct Stack *stack,int size){
    if(isEmpty(stack)){
        return '0';
    }
    return stack->arr[stack->top];
}

bool isValid(char* s){
    struct Stack stack;
    stack.top = -1;
    int n = strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            push(&stack,s[i],n);
        }
        else{
            if(isEmpty(&stack)){
                return false;
            }
            else{
                char ch = peek(&stack,n);
                if((ch=='{' && s[i]=='}') || (ch=='[' && s[i]==']') || (ch=='(' && s[i]==')')){
                    pop(&stack,n);
                }
                else{
                    return false;
                }
            }
        }
    }
    if(isEmpty(&stack)){
        return true;
    }
    return false;
}

int main(){
    char inputString[100];
    scanf("%s",&inputString);
    
    assert(isValid(inputString)==true);
    return 0;
}