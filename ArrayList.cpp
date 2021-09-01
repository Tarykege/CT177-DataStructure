#include <stdio.h>
//initial
#define maxLength 100
typedef int Pos;
typedef int ElementType;
typedef struct{
    ElementType element[maxLength];
    Pos last;
}List;
//method
Pos firstList(List L){
    return 1;
}
Pos endList(List L){
    return L.last+1;
}
Pos next(Pos p, List L){
    return p+1;
}
Pos previous(Pos p){
    return p-1;
}
void makenullList(List *L){
    L->last=0;
}
int emptyList(List L){
    return L.last==0;
}
int fullList(List L){
    return L.last==maxLength;
}

ElementType retrive(Pos p, List L){
    return L.element[p-1];
}
Pos locate(ElementType x, List L){
    Pos p=firstList(L);
    while(p!=endList(L)){
        if(retrive(p,L)==x){
            return p;
        }else p=next(p, L);
    }
    return endList(L);
}
void insertList(ElementType x, Pos p, List *L){
    if(L->last==maxLength && (p<1 || p>endList(*L))){
        printf("List is full & invalid positive");
    }
    else if(L->last==maxLength){
        printf("List is full");
    }else if(p<1 || p>endList(*L)){
        printf("Invalid positive");
    }else {
        //tai sao i dung last trong giao trinh
        for(Pos i=L->last; i>p-1; i=next(i,*L)){
            L->element[i]=L->element[i-1];
        }
        L->element[p-1]=x;
        L->last++;
    }
}
void deleteList (ElementType x, Pos p, List *L){
    if(emptyList(*L)==1 && (p<1 || p>endList(*L))){
        printf("List is empty & invalid positive");
    }
    else if(emptyList(*L)==1){
        printf("List is empty");
    }else if(p<1 || p>L->last){
        printf("Invalid positive");
    }else {
        for(Pos i=p-1; i<=L->last-2; i++){
            L->element[i]=L->element[i+1];
        }
    }
    L->last--;
}
void input(List *L){
    makenullList(L);
    int n;
    printf("quality: "); scanf("%d",&n);
    ElementType x;
    for (int i=1; i<=n; i++){
        printf("Nhap phan tu thu %d: ",i); scanf("%d", &x);
        //insertList(x, i, L);
        insertList(x, endList(*L),L);
    }
}
void output(List L){
    for(int i=firstList(L); i<endList(L); i=next(i,L)){
        printf("%d ",retrive(i,L));
    }
}
int main(){

return 0;
}