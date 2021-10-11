#include<stdio.h>

#define MaxLength 300
typedef int ElementType;
typedef struct{
    ElementType element[MaxLength];
    int top_index;
}Stack;

void makeNullStack(Stack *S){
    S->top_index=MaxLength;
}

int emptyStack(Stack S){
    return S.top_index==MaxLength;
}

int fullStack(Stack S){
    return S.top_index==0;
}

ElementType top(Stack S){
    if(emptyStack(S)){
        printf("Get top Error");
        return NULL;
    }
    else return S.element[S.top_index];

}

void pop(Stack *S){
    if(emptyStack(*S)){
        printf("Pop error");
    }
    else S->top_index++;
}

void push(ElementType x,Stack *S){
    if(fullStack(*S)){
        printf("Push error");
    }
    else {
        S->top_index--;
        S->element[S->top_index]=x;
    }
}

int main(){
    Stack S;
    makeNullStack(&S);
    printf("emptyStack = %d\n",emptyStack(S));
    push(1,&S);
    printf("%d\n",top(S));
    push(2,&S);
    printf("%d\n",top(S));
    push(3,&S);
    printf("%d\n",top(S));
    push(4,&S);
    printf("%d\n",top(S));
    pop(&S);
    printf("%d\n",top(S));
    pop(&S);
    printf("%d\n",top(S));
    pop(&S);
    printf("%d\n",top(S));    
    return 0;
}

