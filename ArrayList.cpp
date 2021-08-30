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
Pos first(List L){
    return 1;
}
Pos end(List L){
    return L.last+1;
}
Pos next(Pos p, List L){
    return p+1;
}
Pos previous(Pos p){
    return p-1;
}
void makeNull(List *L){
    L->last=0;
}
int checkEmpty(List L){
    return L.last==0;
}
//retrive tra ve kieu du lieu ElementType vi day la tra ve gia tri phan tu tai vi tri p
ElementType retrive(Pos p, List L){
    return L.element[p-1];
}
Pos locate(ElementType x, List L){
    //neu khong tim duoc thi tra ve -1
    Pos p=first(L);
    while(p!=end(L)){
        if(retrive(p,L)==x){
            return p;
        }else p=next(p, L);
    }
    return -1;
}
void insertList(ElementType x, Pos p, List *L){
    if(L->last==maxLength && (p<1 || p>end(*L))){
        printf("List is full & invalid positive");
    }
    else if(L->last==maxLength){
        printf("List is full");
    }else if(p<1 || p>end(*L)){
        printf("Invalid positive");
    }else {
        //tai sao i dung last trong giao trinh
        for(Pos i=end(*L); i>p; i=next(i,*L)){
            L->element[i-1]=L->element[i-2];
        }
        L->element[p-1]=x;
        L->last++;
    }
}
void deleteList (ElementType x, Pos p, List *L){
    if(checkEmpty(*L)==1 && (p<1 || p>end(*L))){
        printf("List is empty & invalid positive");
    }
    else if(checkEmpty(*L)==1){
        printf("List is empty");
    }else if(p<1 || p>end(*L)){
        printf("Invalid positive");
    }else {
        for(Pos i=p; i<end(*L); i++){
            L->element[i-1]=L->element[i];
        }
    }
    L->last--;
}
void input(List *L){
    makeNull(L);
    int n;
    printf("quality: "); scanf("%d",&n);
    ElementType x;
    for (int i=1; i<=n; i++){
        printf("Nhap phan tu thu %d: ",i); scanf("%d", &x);
        //insertList(x, i, L);
        insertList(x, end(*L),L);
    }
}
void output(List L){
    for(int i=first(L); i<end(L); i=next(i,L)){
        printf("%d ",retrive(i,L));
    }
}
int main(){

return 0;
}