#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

struct stack{
    int items[MAXSIZE];
    int top;
};

void intializestack(struct stack *s){
    s->top=-1;
}

bool isStackEmpty(struct stack *s){
        return s->top==-1;
}

void push(struct stack *s,int data){
    if(s->top==MAXSIZE-1){
        printf("OVERFLOW");
    }
    s->items[++s->top]=data;
}

void print(struct stack *s){
    int i=s->top;
    while(i>=0){
        printf("%d", s->items[i]);
        i--;

    }
    printf("\n");

}

void pop(struct stack *s) {
    if (s->top == -1) {
        printf("Underflow\n");
        return;
    }
    printf("Element removed is %d\n", s->items[s->top]);
    s->top--;
}

int main(){

    struct stack stacky;
    intializestack(&stacky);

    int i;
    int ch;int number;
    while(true){
        printf("1.push\n 2.pop\n 3.print\n 4.exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                scanf("%d", &number);
                push(&stacky,number);
                break;
            }
            case 2:{
                pop(&stacky);
                break;
            }
            case 3:{
                print(&stacky);
                break;

            }
            case 4:{
                return 0;
            }



        }
    }
    return 0;
}


