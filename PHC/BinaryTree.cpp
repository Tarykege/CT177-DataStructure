#include <stdio.h>
#include <stdlib.h>
typedef char TData;
struct TNode
{
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
    if (n != NULL)
        return n->Left;
    else
        return NULL;
}

TTree rightChild(TTree n){
    if (n != NULL)
        return n->Right;
    else
        return NULL;
}

int isLeaf(TTree n){
    if (n != NULL)
    {
        return (n->Left == NULL) && (n->Right == NULL);
    }
    else
        return 0;
}

void preOrder(TTree T){
    printf("%c", T->Data);
    if (leftChild(T) != NULL)
        preOrder(leftChild(T));
    if (rightChild(T) != NULL)
        preOrder(rightChild(T));
}

void inOrder(TTree T){
    if (leftChild(T) != NULL)
        inOrder(leftChild(T));
    printf("%c", T->Data);
    if (rightChild(T) != NULL)
        inOrder(rightChild(T));
}

void posOrder(TTree T){
    if (leftChild(T) != NULL)
        posOrder(leftChild(T));
    if (rightChild(T) != NULL)
        posOrder(rightChild(T));
    printf("%c", T->Data);
}

int nb_nodes(TTree T){
    if(T==NULL) return 0;
    else 1+nb_nodes(leftChild(T)) + nb_nodes(rightChild(T));
}

TTree Create2(TData v, TTree l, TTree r){
    TTree n;
    n = (struct TNode*) malloc(sizeof(TNode));
    n->Data=v;
    n->Left=l;
    n->Right=r;
    return n;
}

int main(int argc, char const *argv[]){
    
    return 0;
}
