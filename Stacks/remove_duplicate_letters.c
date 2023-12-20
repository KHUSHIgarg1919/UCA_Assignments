#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>
#include <stdlib.h>
#define STACK_SIZE 26                           //Assuming the stack can hold all lowercase letters

typedef struct {
    int* array;
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (int*)malloc(STACK_SIZE * sizeof(int));
    stack->top = -1;
    return stack;
}

void push(Stack* stack, int value) {
    stack->array[++stack->top] = value;
}

int pop(Stack* stack) {
    return stack->array[stack->top--];
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

char* removeDuplicateLetters(char* s) {
    Stack* st = createStack();
    int lastIndex[26] = {0};
    bool seen[26] = {false};

    // Store last index of each character of string in lastIndex array
    for (int i = 0; i < strlen(s); i++) {
        lastIndex[s[i] - 'a'] = i;
    }

    for (int i = 0; i < strlen(s); i++) {
        int curr = s[i] - 'a';

        if (seen[curr]) {
            continue;
        }

        while (!isEmpty(st) && st->array[st->top] > curr && i < lastIndex[st->array[st->top]]) {
            seen[pop(st)] = false;
        }

        push(st, curr);
        seen[curr] = true;
    }

    char* ans = (char*)malloc((st->top + 2) * sizeof(char));
    int index = 0;

    while (!isEmpty(st)) {
        ans[index++] = pop(st) + 'a';
    }

    ans[index] = '\0';

    // Reverse the string
    int start = 0, end = index - 1;
    while (start < end) {
        char temp = ans[start];
        ans[start] = ans[end];
        ans[end] = temp;
        start++;
        end--;
    }
    return ans;
}

int main(){
    char inputString[100];
    scanf("%s",&inputString);
    
    char* ans = removeDuplicateLetters(inputString);
    printf("%s",ans);
    return 0;
}
