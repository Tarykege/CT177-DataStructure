#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node* Position;
typedef Position List;
//======================================================================//
Position firstList(List L){
    return L;
}

Position endList(List L){
    Position p=L;
    while(p->Next!=NULL){
        p=p->Next;
    }
    return p;
}
//======================================================================//
Position next(Position P, List L){
    return P->Next;
}

Position previous(Position P, List L){
    Position q=L;
    while(q->Next!=P){
        q=q->Next;
    }
    return q;
}
//======================================================================//
ElementType retrieve(Position P, List L){
    if(P->Next!=NULL){
        return P->Next->Element;
    }
}
//======================================================================//
void makeNullList(List *L){
 (*L)=(Node*) malloc(sizeof(struct Node));
 (*L)->Next=NULL; //note: required parentheses
}

int emptyList(List L){
    return L->Next==NULL;
}
//======================================================================//
Position locate(ElementType x, List L){
    Position p=L;
    while(p->Next!=NULL){
        if(p->Next->Element==x){
            return p;
        }else p=p->Next;
    }
    return p;
}
//======================================================================//
Position myLocate(ElementType x, int i, List L){
    int count=0;
    Position p=L;
    while(p->Next!=NULL){
        if(p->Next->Element==x){
            count++;
        }
        if(count==i){
            return p;
        }else p=p->Next;

    }
    return p;
}
//======================================================================//
void insertList(ElementType X, Position P, List* L){
    Position T;
    T= (Node*) malloc(sizeof(struct Node));
    T->Element=X;
    T->Next=P->Next;
    P->Next=T;
}

void append(ElementType x, List *L){
    Position t;
    Position p=*L;
    t= (struct Node*) malloc(sizeof(struct Node));
    t->Next=NULL;
    t->Element=x;
    while(p->Next!=NULL){
        p=p->Next;
    }
    t->Next=p->Next;
    p->Next=t;
}

void addFirst(ElementType x, List *L){
    Position t;
    Position p=*L;
    makeNullList(&t);
    t->Element=x;
    t->Next=p->Next;
    p->Next=t;
}
//======================================================================//
void deleteList(Position P, List* L){
    Position T;
    T=P->Next;
    P->Next=T->Next;
    free(T);
}

void removeAllX(ElementType x, List *L){
    Position p;
    do{
        p=locate(x,*L);
        if(p->Next!=NULL) deleteList(p,L);
    }while(p->Next!=NULL);
}
//======================================================================//
void swap(Position p, Position q, List *L){
    ElementType temp;
    temp=retrieve(p,*L);
    p->Next->Element=retrieve(q,*L);
    q->Next->Element=temp;
}

void sortList(List *L){
    Position i=*L;
    while(i!=endList(*L)){
        Position j=next(i,*L);
        while(j!=endList(*L)){
            if(retrieve(i,*L)>retrieve(j,*L)) {
                swap(i,j,L);
            }
            j=next(j,*L);
        }
        i=next(i,*L);
    }
}
//======================================================================//
int member(ElementType x, List L){
    Position p=L;
    while(p->Next!=NULL){
        if(p->Next->Element==x){
            return 1;
        }    
        else p=p->Next;
    }
    return 0;
}
List unionSet(List L1, List L2){
    Position p=L1;
    Position q=L2;
    List L3;
    makeNullList(&L3);
    while(p->Next!=NULL){
        append(p->Next->Element,&L3);
        p=p->Next;
    }
    while(q->Next!=NULL){
        if(!member(q->Next->Element,L1)) append(q->Next->Element,&L3);
        q=q->Next;
    }
    return L3;
}

List intersection(List L1, List L2){
    Position p=L1;
    Position q=L2;
    List L3;
    makeNullList(&L3);
    while(p->Next!=NULL){
        append(p->Next->Element,&L3);
        p=p->Next;
    }
    while(q->Next!=NULL){
        if(member(q->Next->Element,L1)) append(q->Next->Element,&L3);
        q=q->Next;
    }

    Position L4;
    makeNullList(&L4);
    Position z = L3;
    while(z->Next!=NULL){
        Position x=z->Next;
        while(x->Next!=NULL){
            if(z->Next->Element==x->Next->Element && !member(z->Next->Element,L4)){
                append(z->Next->Element,&L4);
                break;
            }
            x=x->Next;
        }
        z=z->Next;
    }

    return L4;
}
//======================================================================//
void input(List *L){
    makeNullList(L);
    int n;
    printf("Nhap so luong: ");
    scanf("%d",&n);
    ElementType x;
    for(int i=0; i<n; i++){
        printf("nhap gia tri %d: ",i+1);
        scanf("%d", &x);
        insertList(x,endList(*L),L);
    }
}

void output(List L){
    Position p=L;
    while(p->Next!=NULL){
        printf("%d ", p->Next->Element);
        p=p->Next;
    }
    printf("\n");
}
//======================================================================//
int main(){
    List L;
    ElementType x;
    Position P;
    input(&L);
    output(L); 
    printf("\n");
    printf("Nhap phan tu can them: ");
    scanf("%d",&x);
    insertList(x,endList(L),&L);
    output(L);
    printf("Nhap noi dung phan tu can xoa: ");
    scanf("%d",&x);
    P=locate(x,L);
    deleteList(P,&L);
    printf("In danh sach sau khi xoa: ");
    output(L);
    printf("Sap xep: ");
    sortList(&L);
    output(L);
    return 0;
}