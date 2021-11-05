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
    else return NULL;
}
//xac dinh con phai
Tree rightChild(Tree n){
    // checked
    if(n!=NULL) return n->Right;
    else return NULL;
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
    // checked
    if(T==NULL) return 0;
    else return 1+nb_nodes(T->Left)+nb_nodes(T->Right);
}
// duyet tien tu
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
//ham tao mot cay tra ve la mot cay voi nhan la key
Tree getNewNode(int key){
    Tree T = (struct Node*) malloc(sizeof(struct Node));
    T->Key=key;
    T->Left=NULL;
    T->Right=NULL;
    return T;
}
//them node
void insertNode(Tree* pRoot, int x){
    // chua check
    //Chia 3 truong hop: root se tra ve khi gap NULL, x < key thi se goi T->Left, x > key thi goi T->Right
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
    makenullTree(&T);
    while(true){
        printf("\n======== Menu ========");
        printf("\nEnter 1: add tree");
        printf("\nEnter 2: print tree");
        printf("\nEnter 3: search tree");
        printf("\nEnter 4: Numer of tree");
        printf("\nEnter 5: exit");
        printf("\n======================");  
        int choose;
        printf("\nNhap lua chon: ");  
        scanf("%d",&choose);
        if(choose< 0 || choose >5){
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
            printf("\n%d",nb_nodes(T));
        }
        else if(choose == 5){
            system("cls");
            return;
        }
    }
}
int main(){
    menu();
}