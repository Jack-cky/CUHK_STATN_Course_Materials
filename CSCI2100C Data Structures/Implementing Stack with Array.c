/*
I, CHAN King Yeung, am submitting the assignment for
an individual project.
I declare that the assignment here submitted is original except for
source material explicitly acknowledged, the piece of work, or a part
of the piece of work has not been submitted for more than one purpose
(i.e. to satisfy the requirements in two different courses) without
declaration. I also acknowledge that I am aware of University policy
and regulations on honesty in academic work, and of the disciplinary
guidelines and procedures applicable to breaches of such policy and
regulations, as contained in the University website
http://www.cuhk.edu.hk/policy/academichonesty/.
It is also understood that assignments without a properly signed
declaration by the student concerned will not be graded by the
teacher(s).
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum {push = 1, pop, end, isfull, isempty} Operation;

struct Stack {
    int * arr;
    int capacity;
    int top;
};

struct Stack * Create(int capacity) {
    struct Stack * stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->arr = (int*)malloc(sizeof(int) * capacity);
    stack->capacity = capacity;
    stack->top = 0;
    return stack;
}

int IsFull(struct Stack * stack) {
    // write your code here
    
    return(stack->top == stack->capacity);
}

int IsEmpty(struct Stack * stack) {
    // write your code here
    
    return(stack->top == 0);
}

int Push(struct Stack * stack, int x) {
    // write your code here
    
    if(IsFull(stack))
        return 1e5;
    
    stack->arr[stack->top] = x;
    
    stack->top++;
    
    return 0;
}

int Pop(struct Stack * stack) {
    // write your code here
        
    if(IsEmpty(stack))
        return 1e5;
        
    stack->top--;
        
    return 0;
}

Operation Getop() {
    char str[10];
    scanf("%s", str);
    if (strcmp(str, "Push") == 0) {
        return 1;
    }
    else if (strcmp(str, "Pop") == 0) {
        return 2;
    }
    else if (strcmp(str, "End") == 0) {
        return 3;
    }
    else if (strcmp(str, "Isfull") == 0) {
        return 4;
    }
    else if (strcmp(str, "Isempty") == 0) {
        return 5;
    }
    else {
        return 0;
    }
}

void printArray(struct Stack * stack) {
    int i;
    for (i = 0; i < stack->top; i++) {
        if(i != stack->top - 1) {
            printf("%d ", stack->arr[i]);
        }
        else {
            printf("%d\n", stack->arr[i]);
        }
    }
}

int main(void) {
    int X;
    int capacity;
    struct Stack * stack;
    int flag = 0;

    scanf("%d", &capacity);
    stack = Create(capacity);
    while (!flag) {
        switch(Getop()) {
            case push:
                scanf("%d", &X);
                if (Push(stack, X) == 1e5) {
                    printf("Stack is full\n");
                }
                break;
            case pop:
                X = Pop(stack);
                if (X == 1e5) {
                    printf("Stack is empty\n");
                }
                break;
            case end:
                printArray(stack);
                flag = 1;
                break;
            case isfull:
                if (IsFull(stack)){
                    printf("Stack is full\n");
                }
                else{
                    printf("Stack is not full\n");
                }
                break;
            case isempty:
                if (IsEmpty(stack)){
                    printf("Stack is empty\n");
                }
                else{
                    printf("Stack is not empty\n");
                }
                break;
        }
    }
    return 0;
}
