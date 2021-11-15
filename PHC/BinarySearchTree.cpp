#include <stdio.h>
#include <stdlib.h>
typedef int TData;
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
    printf("%d", T->Data);
    if (leftChild(T) != NULL)
        preOrder(leftChild(T));
    if (rightChild(T) != NULL)
        preOrder(rightChild(T));
}

void inOrder(TTree T){
    if (leftChild(T) != NULL)
        inOrder(leftChild(T));
    printf("%d", T->Data);
    if (rightChild(T) != NULL)
        inOrder(rightChild(T));
}

void posOrder(TTree T){
    if (leftChild(T) != NULL)
        posOrder(leftChild(T));
    if (rightChild(T) != NULL)
        posOrder(rightChild(T));
    printf("%d", T->Data);
}

int nb_nodes(TTree T){
    if(T==NULL) return 0;
    else return 1+nb_nodes(leftChild(T)) + nb_nodes(rightChild(T));
}

TTree Create2(TData v, TTree l, TTree r){
    TTree n;
    n = (struct TNode*) malloc(sizeof(TNode));
    n->Data=v;
    n->Left=l;
    n->Right=r;
    return n;
}
//SearchNode
TTree Search(TData x, TTree Root){
    if(Root == NULL) return NULL;
    else if(Root->Data == x) return Root;
    else if(Root->Data>x) return Search(x,Root->Left);
    else return Search(x,Root->Right);
}
//insertNode
void insertNode(TData x, TTree *Root){
    if(*Root == NULL){
        (*Root) = (struct TNode*) malloc(sizeof(struct TNode));
        (*Root)->Data = x;
        (*Root)->Left=NULL;
        (*Root)->Right=NULL;
    }
    else if(x < (*Root)->Data) insertNode(x, &((*Root)->Left));
    else if(x > (*Root)->Data) insertNode(x, &((*Root)->Right)); 
}
//DeletMin
TData DeleteMin (TTree *Root){
    TData k;
    if((*Root)->Left==NULL){
        k = (*Root)->Data;
        (*Root) = (*Root)->Right;
        return k;
    }
    else return DeleteMin(&((*Root)->Left));
}
//DeleteNode
void DeleteNode(TData x, TTree *Root){
    //(*Root)
    if((*Root) != NULL)
        //Hy vong x ben trai
        if(x < (*Root)->Data) DeleteNode(x, &((*Root)->Left));
        ////Hy vong x ben phai
        else if(x > (*Root)->Data) DeleteNode(x, &((*Root)->Right)); 
        else // Tim duoc node co data la x
        // node la nut la
        if((*Root)->Left == NULL && (*Root)->Right == NULL){
            (*Root) = NULL;
        }
        // node chi co con phai
        else if((*Root)->Left == NULL){
            (*Root) = (*Root)->Right;
        }
        // node chi co con trai
        else if((*Root)->Right == NULL){
            (*Root) = (*Root)->Left;
        }
        // node co 2 con trai va con phai
        else (*Root)->Data = DeleteMin(&((*Root)->Right));
}
void menu(){
    TTree T;
    makenullTree(&T);
    while(true){
        printf("\n======== Menu ========");
        printf("\nEnter 1: add tree");
        printf("\nEnter 2: print tree");
        printf("\nEnter 3: search tree");
        printf("\nEnter 4: Numer of tree");
        printf("\nEnter 5: DeleteTree");
        printf("\nEnter 6: exit");
        printf("\n======================");  
        int choose;
        printf("\nNhap lua chon: ");  
        scanf("%d",&choose);
        if(choose< 0 || choose >6){
            printf("\nLua chon khong hop le");
            return;
        }
        else if(choose == 1){
            system("cls");
            int x;
            printf("\nNhap so nguyen x:");
            scanf("%d",&x);
            //ThemNode()
            insertNode(x,&T);
        }
        else if(choose == 2){
            system("cls");
            printf("\n 1: tien tu");
            printf("\n 2: trung tu");
            printf("\n 3: hau tu");
            
            int x;
            printf("\nLoai duyet: ");
            scanf("%d",&x);
            if(x == 1){
                preOrder(T);
            }
            if(x == 2){
                inOrder(T);
            }
            if(x == 3){
                posOrder(T);
            }
        }
        else if(choose == 3){
            system("cls");
            printf("\nNhap Key can tim: ");
            int x;
            scanf("%d",&x);
            //seachNode(x,T);
        }
        else if(choose == 4){
            system("cls");
            printf("\n%d",nb_nodes(T));
        }
        else if(choose == 5){
            system("cls");
            int x;
            scanf("%d",&x);
            DeleteNode(x, &T);
        }
        else if(choose == 6){
            system("cls");
            return;
        }
    }
}
int main(){
    menu();
    return 0;
}
