#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include <stdbool.h>

#define MAX_QUEUE 0xFF

char queue[MAX_QUEUE];
int front, back, count;

void init();
const bool isEmpty();
bool enqueue(const char newEntry);
bool dequeue();
const char dequeue2();

void killqueue();

//const char peekFront();

#endif
