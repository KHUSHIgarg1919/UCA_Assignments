#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
    int top;
    int *arr;
    int maxSize;
} Stack;

Stack *createStack(){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->maxSize = 100;
    stack->arr = (int *)malloc(100 * sizeof(int));
    return stack;
}

bool isEmpty(Stack *stack){
    if (stack->top == -1){
        return true;
    }
    return false;
}

bool isFull(Stack *stack){
    if (stack->top == stack->maxSize - 1){
        return true;
    }
    return false;
}

void push(Stack *stack, int x){
    if (isFull(stack)){
        return;
    }
    stack->arr[++stack->top] = x;
    return;
}

int pop(Stack *stack){
    if (isEmpty(stack)){
        return -1;
    }
    int temp = stack->arr[stack->top];
    stack->top--;
    return temp;
}

int evaluatepostfix(char *str_array[]){
    Stack *mystack = createStack();
    int i = 0;
    while (str_array[i][0] != '?')
    {
        char *ch = str_array[i];
        if (strcmp(ch, "*") == 0 || strcmp(ch, "/") == 0 || strcmp(ch, "+") == 0 || strcmp(ch, "-") == 0){
            int num1 = pop(mystack);
            int num2 = pop(mystack);
            if (strcmp(ch, "*") == 0){
                push(mystack, num2 * num1);
            }
            else if (strcmp(ch, "/") == 0){
                push(mystack, num2 / num1);
            }
            else if (strcmp(ch, "+") == 0){
                push(mystack, num2 + num1);
            }
            else{
                push(mystack, num2 - num1);
            }
        }
        else{
            int ans = atoi(ch);
            push(mystack, ans);
        }
        i++;
    }
    return pop(mystack);
}
int main(){
    int n;
    scanf("%d", &n);
    while (n--){
        char *str_array[100]; 
        char ch[100];
        int i = 0;
        scanf("%s ", ch);
        str_array[i] = (char *)malloc(strlen(ch) * sizeof(char));
        strcpy(str_array[i], ch);
        while (strcmp(str_array[i], "?") != 0){
            i++;
            scanf("%s ", ch);
            str_array[i] = (char *)malloc(strlen(ch) * sizeof(char));
            strcpy(str_array[i], ch);
        }
        int ans = evaluatepostfix(str_array);
        printf("%d\n", ans);
    }
    return 0;
}