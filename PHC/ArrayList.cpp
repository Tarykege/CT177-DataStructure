#include <stdio.h>

#define MaxLength 300
typedef int ElementType;
typedef int Position;
typedef struct{
    ElementType element[MaxLength];
    Position Last;
}List;

List L;
void makeNullList(List *pL){
   pL->Last=0;
}

int emptyList(List L){
    return L.Last==0;
}

int fullList(List L){
    return L.Last==MaxLength;
}

Position first(List L){
    return 1;
}

Position endList(List L){
    return L.Last+1;
}
//======================================================================//
void insertList(ElementType x, Position P, List *pL){
    Position Q;
    if(pL->Last==MaxLength) printf("List is full!");
    else if (P<1 || P>pL->Last+1) printf("Position invalid!");
    else{
        for(Q=pL->Last; Q>=P; Q--){
            pL->element[Q]=pL->element[Q-1];
        }
        pL->element[P-1]=x;
        pL->Last++;
    }
}
//======================================================================//
void deleteList(Position P, List *pL){
    if((P<1) || (P>pL->Last)) printf("Position invalid");
    else if(emptyList(*pL)){
        printf("List is empty!");
    }
    else{
        Position Q;
        for(Q=P; Q<=pL->Last-1;Q++){
            pL->element[Q-1]=pL->element[Q];
        }
        pL->Last--;
    }
}
//======================================================================//
Position next(Position P, List L){
    return P+1;
}

Position previous(Position P, List L){
    return P-1;
}

ElementType retrieve(Position P, List L){
    return L.element[P-1];
}
//======================================================================//
Position locate(ElementType x, List L){
    Position P=1;
    while(P!=L.Last+1){
        if(retrieve(P,L)==x){
            return P;
        }
        else P=next(P,L);
    }
    return P;
}
//======================================================================//
void deleteDuplicate(ElementType x, List *pL){
    Position P=1;
    while(P!=pL->Last+1){
        if(pL->element[P-1]==x){
            deleteList(P,pL);
        }
        P++;
    }
}
//======================================================================//
void swap(Position P, Position Q, List *pL){
     ElementType t = pL->element[P];
                pL->element[P] = pL->element[Q];
                pL->element[Q]=t;
}

void sortList(List *pL){
    //@Bubblesort//
    for(int i=0; i<pL->Last; i++){
        int isSorted=false;
        for(int j=0; j<pL->Last-i-1; j++){
            if(pL->element[j]>pL->element[j+1]){
                isSorted=true;
               swap(j,j+1,pL);
            }
        }
        if(!isSorted) break;
    }
}
//======================================================================//
void readList(List *pL){
    int i,n;
    ElementType x;
    makeNullList(pL);
    printf("Enter quality: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("set x%d: ",i+1);
        scanf("%d",&x);
        insertList(x,endList(*pL),pL);
    }
}
//======================================================================//
void printList(List L){
    Position P=1;
    while(P!=L.Last+1){
        printf("%d ",L.element[P-1]);
        P++;
    }
    printf("\n");
}
//======================================================================//
int main(){
    List L;
    ElementType x;
    Position P;
    readList(&L);
    printList(L);
    printf("Enter any value to add: ");
    scanf("%d",&x);
    printf("Enter position to add: ");
    scanf("%d",&P);
    insertList(x,P,&L);
    printList(L);
    printf("Enter value in list to delete: ");
    scanf("%d",&x);
    P=locate(x,L);
    deleteList(P,&L);
    printList(L);
    printf("Enter value to delete every of value in list:");
    scanf("%d",&x);
    deleteDuplicate(x,&L);
    printList(L);
    printf("Sorting list: ");
    sortList(&L);
    printList(L);
}


