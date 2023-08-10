#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10

struct stack {
    int items[MAXSIZE];
    int minItems[MAXSIZE]; // To track minimum elements
    int top;
};

void initializeStack(struct stack *s) {
    s->top = -1;
}

bool isStackEmpty(struct stack *s) {
    return s->top == -1;
}

void push(struct stack *s, int data) {
    if (s->top == MAXSIZE - 1) {
        printf("OVERFLOW\n");
        return;
    }

    s->top++;
    s->items[s->top] = data;

    if (s->top == 0 || data <= s->minItems[s->top - 1]) {
        s->minItems[s->top] = data;
    } else {
        s->minItems[s->top] = s->minItems[s->top - 1];
    }
}

void pop(struct stack *s) {
    if (isStackEmpty(s)) {
        printf("Underflow\n");
        return;
    }

    printf("Element removed is %d\n", s->items[s->top]);
    s->top--;

    // Don't pop from the min stack here
}

int min(struct stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }

    return s->minItems[s->top];
}

int main() {
    struct stack mainStack;
    struct stack minStack;
    initializeStack(&mainStack);
    initializeStack(&minStack);

    int ch;
    int number;

    while (true) {
        printf("1.push\n2.pop\n3.min\n4.exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                scanf("%d", &number);
                push(&mainStack, number);
                if (isStackEmpty(&minStack) || number <= min(&minStack)) {
                    push(&minStack, number);
                }
                break;
            }
            case 2: {
                pop(&mainStack);
                pop(&minStack); // Pop from minStack as well
                break;
            }
            case 3: {
                int minimum = min(&minStack);
                if (minimum != -1) {
                    printf("Minimum element is %d\n", minimum);
                }
                break;
            }
            case 4: {
                return 0;
            }
        }
    }
    return 0;
}
