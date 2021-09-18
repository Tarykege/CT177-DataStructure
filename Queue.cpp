#include <stdio.h>
#define MaxLength 10
typedef int ElementType;
typedef struct{
    ElementType element[MaxLength];
    int front;
    int rear;

}Queue;

void makeNullQueue(Queue *Q){
    Q->front=-1;
    Q->rear=-1;
}

int emptyQueue(Queue Q){
    return Q.front==-1;
}

int fullQueue(Queue Q){
    return (Q.rear-Q.front+1)%MaxLength == 0;
}

ElementType front(Queue Q){
    if(emptyQueue(Q)){
    printf("Error has not element to print\n");
    }
    else return Q.element[Q.front];
}

void enQueue(ElementType x,Queue *Q){
    if(fullQueue(*Q)) printf("Queue is full!\n");
    else{
        if(emptyQueue(*Q)) Q->front=0;
        Q->rear=(Q->rear+1)%MaxLength;
        Q->element[Q->rear]=x;
    }
}

void deQueue(Queue *Q){
    if(emptyQueue(*Q)) printf("Error queue is empty to deQueue\n");
    else{
        if(Q->front==Q->rear) makeNullQueue(Q);
        else Q->front=(Q->front+1)%MaxLength;
    }
}