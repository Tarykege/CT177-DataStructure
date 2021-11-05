#include <stdio.h>
#include <stdlib.h>
typedef char TData;
struct TNode{
    TData Data;
    struct TNode *Left;
    struct TNode *Right;
};
typedef struct TNode *TTree;

void makenullTree(TTree *T){
    (*T) = NULL;
}
int emptyTree(TTree T){
    return T == NULL;
}
TTree leftChild(TTree n){
    if(n!=NULL){
        return n->Left;
    }
    else return NULL;
}
TTree rightChild(TTree n){
    if(n!=NULL){
        return n->Right;
    }
    else return NULL;
}
int isLeaf(TTree n){
    if(n!=NULL){
        return (n->Left ==NULL) && (n->Right==NULL);
    }
    else return 0;
}

void preOrder(TTree T){
    printf("%d",T->Data);
    if(T->Left !=NULL) preOrder(T->Left);
    if(T->Right !=NULL) preOrder(T->Right);

}
void inOrder(TTree T){
    if(T->Left !=NULL) inOrder(T->Left);
    printf("%d",T->Data);
    if(T->Right !=NULL) inOrder(T->Right);
}
void posOrder(TTree T){
    if(T->Left !=NULL) posOrder(T->Left);
    if(T->Right !=NULL) posOrder(T->Right);
    printf("%d",T->Data);
}
int nb_nodes(TTree T){
    if(T==NULL) return 0;
    else return 1+nb_nodes(T->Left)+nb_nodes(T->Right);
}
TTree Create2(TData v, TTree l, TTree r){
    TTree n;
    n = (struct TNode*) malloc(sizeof(struct TNode));
    n->Data=v;
    n->Left=l;
    n->Right=r;
    return n;
}
int main(){
    
}


























// #define MaxLength 10
// typedef int ElementType;
// typedef struct
// {
//     ElementType element[MaxLength];
//     int front;
//     int rear;
// } Queue;

// void makeNullQueue(Queue *Q)
// {
//     Q->front = -1;
//     Q->rear = -1;
// }

// int emptyQueue(Queue Q){
//     return Q.front==-1;
// }

// int fullQueue(Queue Q){
//     return (Q.rear-Q.front+1) % MaxLength == 0;
// }
// ElementType Front(Queue Q){
//     if(emptyQueue(Q)){
//         printf("Error has not element to retrieve\n");
//         return -404;
//     }
//     else return Q.element[Q.front];
// }
// void enQueue(ElementType x, Queue *Q){
//     if(fullQueue(*Q)) printf("Queue is full\n");
//     else{
//         if(emptyQueue(*Q)) Q->front=0;
//         Q->rear=(Q->rear+1) % MaxLength;
//         Q->element[Q->rear]=x;
//     }
// }
// void deQueue(Queue *Q){
//     if(emptyQueue(*Q)) printf("Error queue is empty to deQueue\n");
//     else{
//         if(Q->front==Q->rear) makeNullQueue(Q);
//         else Q->front = (Q->front+1) % MaxLength;
//     }
// }
// int main(){
//     Queue Q;
//     makeNullQueue(&Q);
//     printf("%d",emptyQueue(Q));
//     printf("\n%d",fullQueue(Q));
//     enQueue(100,&Q);
//     enQueue(101,&Q);
//     deQueue(&Q);
//     printf("\n%d",Q.element[Q.front]);
//     printf("\n%d",Q.element[Q.rear]);
// }
