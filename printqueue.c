#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX 10
typedef int itemtype; 
typedef struct {
    itemtype item [MAX]; 
    int front; 
    int rear; 
    int count;
} queue; 

void inisialisasi (queue *q) {
    q->front = 0; 
    q->rear = -1; 
    q->count = 0;
}

int penuh (queue *q) {
    return (q->count == MAX);  
}

int kosong (queue *q) {
    return (q->count == 0); 
}

void enqueue (queue *q, itemtype x) { 
    if (penuh(q)) {
        printf("Antrian printer penuh!\n");
        return; 
    }

    q->rear = (q->rear +1) % MAX; 
    q->item[q->rear] = x; 
    q->count++; 
    printf ("Dokumen %d telah masuk antrian\n", x);
}

void dequeue (queue *q) {
    if(kosong(q)) {
        printf("Antrian kosong\n"); 
        return; 
    }

    itemtype temp = q->item[q->front]; 
    
    q->front = (q->front + 1) % MAX; 
    q->count--;
    
    return temp; 
}