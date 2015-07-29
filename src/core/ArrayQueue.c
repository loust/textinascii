#ifndef ARRAYQUEUE_C
#define ARRAYQUEUE_C
#include <stdio.h>
#include <string.h>

#include "../headers/ArrayQueue.h"

void init(){
    back = (MAX_QUEUE - 1);
    front = 0;
    count = 0;
}

const bool isEmpty(){
    return (count == 0);
}

bool enqueue(const char newEntry){
    bool result = false;
    if (count < MAX_QUEUE){
        back = (back + 1) % MAX_QUEUE;
        queue[back] = newEntry;
        result = true;
        count++;
    }
    return result;
}

bool dequeue(){
    bool result = false;
    if (!isEmpty()){
        front = (front + 1) % MAX_QUEUE;
        result = true;
        --count;
    }
    return result;
}

const char dequeue2(){
    if (!isEmpty()){
        char char_holder = queue[front];
        front = (front + 1) % MAX_QUEUE;
        --count;
        return char_holder;
    }
}

void killqueue(){
    back = (MAX_QUEUE - 1);
    front = 0;
    count = 0;
    memset(queue,0,MAX_QUEUE);
}

//const char peekFront(){
//    if (isEmpty()){
//        printf("Queue is empty\n");
//    }else{
//        return queue[front];
//    }
//}

#endif
