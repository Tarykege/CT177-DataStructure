#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
struct Node{
    KeyType Key;
    struct Node *Left;
    struct Node *Right;
};
typedef struct Node* Tree;

//lam rong
void makenullTree(Tree *T){
    //checked
    (*T)=NULL;
}
//kiem tra rong
int emptyTree(Tree T){
    // checked
    return T==NULL;
}
//xac dinh con trai
Tree leftChild(Tree n){
    // checked
    if(n!=NULL) return n->Left;
}
//xac dinh con phai
Tree rightChild(Tree n){
    // checked
    if(n!=NULL) return n->Right;
}
//kiem tra co phai mot nut hay khong
int isLeaf(Tree n){
    // checked
    if(n!=NULL){
        return (n->Left==NULL && n->Right==NULL);
    }
    else return 0;
}
//xac dinh so nut trong cay
int nb_nodes(Tree T){
    // chua check
}
//duyet tien tu
void preOrder(Tree T){
    // checked
    if(T!=NULL){
    printf("%d ",T->Key);
    preOrder(T->Left);
    preOrder(T->Right);
    } 
}
//duyet trung tu
void inOrder(Tree T){
    //checked
    if(T!=NULL){
        inOrder(T->Left);
        printf("%d ",T->Key);
        inOrder(T->Right);
    }
}
//duyet hau tu
void posOrder(Tree T){
    // checked
    if(T!=NULL){
        posOrder(T->Left);
        posOrder(T->Right);
        printf("%d ",T->Key);
    }
}
//tao cay moi tu 2 cay co san
Tree create2(KeyType v, Tree l, Tree r){

    return NULL;

}
//tim kiem mot nut co khoa x
Tree search(KeyType x, Tree Root){
    return NULL;

}
//them node
Tree getNewNode(int key){
    Tree T = (struct Node*) malloc(sizeof(struct Node));
    T->Key=key;
    T->Left=NULL;
    T->Right=NULL;
    return T;
}
void insertNode(Tree* pRoot, int x){
    // chua check
    
    if((*pRoot)==NULL) {
        (*pRoot)=getNewNode(x);
        // (*pRoot) = (struct Node*) malloc(sizeof(struct Node));
        // (*pRoot)->Key=x;
        // (*pRoot)->Left=NULL;
        // (*pRoot)->Right=NULL;
    }
    else if((*pRoot)->Key>x){
        insertNode(&((*pRoot)->Left),x);
    }
    else if((*pRoot)->Key<x){
        insertNode(&((*pRoot)->Right),x);
    }
}
//xoa mot node co nhan x
void deleteNode(KeyType x, Tree *pRoot){

}
KeyType deleteMin(Tree *pRoot){
    return 1;
}
void menu(){
    Tree T;
    while(true){
        printf("\n======== Menu ========");
        printf("\nEnter 1: add tree");
        printf("\nEnter 2: print tree");
        printf("\nEnter 3: search tree");
        printf("\nEnter 4: exit");
        printf("\n======================");  
        int choose;
        printf("\nNhap lua chon: ");  
        scanf("%d",&choose);
        if(choose< 0 || choose >4){
            printf("\nLua chon khong hop le");
            return;
        }
        else if(choose == 1){
            system("cls");
            int x;
            printf("\nNhap so nguyen x:");
            scanf("%d",&x);
            //ThemNode()
            insertNode(&T,x);
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
            return;
        }
    }
}
int main(){
    menu();
}