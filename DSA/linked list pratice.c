#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 15

struct stack{
    int items[MAX_SIZE];
    int top;
};

void intialize_stack(struct stack *s){
    s->top=-1;
}

bool isStackEmpty(struct stack *s){
    return s->top==-1;
}

void push(struct stack *s, int value){
    if(s->top==MAX_SIZE-1){
            printf("Stack overflow");
            return;
    }
    s->items[++s->top]=value;

}

bool checkprime(int num){
    int i;
    if(num<1){
        return false;
    }
    for(i=2;i<=num/2;i++){
            if(num%i==0){
                return false;
    }

        }
    return true;
}

int main(){

    struct stack stacky;
    intialize_stack(&stacky);
    int n, num;
    scanf("%d", &n);
    while(n--){

        scanf("%d", &num);
        if(checkprime(num)){
        push(&stacky,num);
        }
    }
    while (!isStackEmpty(&stacky)) {
        printf("%d ", stacky.items[stacky.top--1]);
        stacky.top--;
    }


    return 0;

}
