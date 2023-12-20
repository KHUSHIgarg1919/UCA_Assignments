#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Stack {
    int *arr;
    int top;
    int capacity;
};

void initialize(struct Stack *stack, int capacity) {
    stack->arr = (int *)malloc(capacity * sizeof(int));
    if (stack->arr == NULL) {
        return;
    }
    stack->top = -1;
    stack->capacity = capacity;
}

void push(struct Stack *stack, int element) {
    if (stack->top == stack->capacity - 1) {
        return;
    }
    stack->top++;
    stack->arr[stack->top] = element;
}

int pop(struct Stack *stack) {
    if (stack->top == -1) {
        return 0;
    }
    return stack->arr[stack->top--];
}

int peek(struct Stack *stack) {
    if (stack->top == -1) {
        return 0;
    }
    return stack->arr[stack->top];
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int longestValidParentheses(char *s) {
    struct Stack st;
    initialize(&st, 10000);
    push(&st, -1);

    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch == '(') {
            push(&st, i);
        } else {
            if(!isEmpty(&st))
            pop(&st);
            if (!isEmpty(&st)) {
                result = (i - peek(&st) > result) ? i - peek(&st) : result;
            } else {
                push(&st, i);
            }
        }
    }

    free(st.arr);
    return result;
}
int main() {
    char exp[100];
    scanf("%s",&exp);
    
    int result = longestValidParentheses(exp);
    printf("%d\n", result);
    return 0;
}