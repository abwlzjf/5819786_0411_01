#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef int element;

typedef struct Stacktype {
    element data[MAX_STACK_SIZE];
    int top;
} Stacktype;

void init(Stacktype* sptr) {
    sptr->top = -1;
}

int is_full(Stacktype* sptr) {
    return (sptr->top == MAX_STACK_SIZE - 1);
}

int is_empty(Stacktype* sptr) {
    return (sptr->top == -1);
}

void push(Stacktype* sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack is Full!\n");
        return;
    }
    else {
        sptr->top++;
        sptr->data[sptr->top] = item;
    }
}

element pop(Stacktype* sptr) {
    element r;
    if (is_empty(sptr)) {
        fprintf(stderr, "Stack is Empty!\n");
        return -1;
    }
    else {
        r = sptr->data[sptr->top];
        sptr->top--;
        return r;
    }
}

int main() {
    Stacktype s;
    int rand_num;
    srand(time(NULL));

    init(&s);
    for (int i = 0; i < 30; i++) {
        rand_num = (rand() % 100) + 1;
        if (i == 0) printf("%d time\n", i + 1);
        else printf("%d times\n", i + 1);
        printf("current num = %d \n", rand_num);

        if (rand_num % 2 == 0) {
            push(&s, rand_num);
            printf("Push Stack S: %d\n", rand_num);
        }
        else {
            rand_num = pop(&s);
            printf("Pop Stack S: %d\n", rand_num);
        }
        printf("\n");
    }
}