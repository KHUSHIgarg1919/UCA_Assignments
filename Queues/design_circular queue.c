#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int* arr;
    int size;
    int front;
    int rear;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->size = k;
    obj->arr = (int*)malloc(k * sizeof(int));
    obj->front = -1;
    obj->rear = -1;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == -1 && obj->rear == -1;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->front == 0 && obj->rear == obj->size - 1) || (obj->rear == (obj->front - 1 + obj->size) % obj->size);
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    } else if (obj->front == -1) {
        obj->front = 0;
        obj->rear = 0;
    } else if (obj->rear == obj->size - 1 && obj->front != 0) {
        obj->rear = 0;
    } else {
        obj->rear++;
    }
    obj->arr[obj->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->front == -1) {
        return false;
    }
    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else if (obj->front == obj->size - 1) {
        obj->front = 0;
    } else {
        obj->front++;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->arr[obj->rear];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}