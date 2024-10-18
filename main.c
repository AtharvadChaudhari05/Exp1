

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct stack
{
    int items[MAX];
    int top;
} stack;
void initialize(stack *s);
int isFull(stack *s);
int isEmpty(stack *s);
void push(stack *s, int value);
int pop(stack *s);
int peek(stack *s);
void display(stack *s);
int main() {
    stack s;
     int choice, value;
    initialize(&s);
    while(1) {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek/Top\n");
        printf("4. Check if Stack is Empty\n");
        printf("5. Check if Stack is Full\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if(isFull(&s)) {
                    printf("Stack is full\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(&s, value);
                }
                break;
            case 2:
                if(isEmpty(&s)) {
                    printf("Stack is empty. Cannot pop\n");
                } else {
                    printf("Popped value: %d\n", pop(&s));
                }
                break;
            case 3:
                if(isEmpty(&s)) {
                    printf("Stack is empty. Cannot peek\n");
                } else {
                    printf("Top value: %d\n", peek(&s));
                }
                break;
            case 4:
                if(isEmpty(&s)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                if(isFull(&s)) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            case 6:
                display(&s);
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void initialize(stack *s) {
    s->top = -1;
}
int isFull(stack *s) {
    return s->top == MAX - 1;
}
int isEmpty(stack *s) {
    return s->top == -1;
}
void push(stack *s, int value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value;
        printf("%d pushed into stack.\n", value);
    }
}
int pop(stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return -1; // Return -1 if the stack is empty
}
int peek(stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1; // Return -1 if the stack is empty
}
void display(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->items[i]);
        }
    }
}


















