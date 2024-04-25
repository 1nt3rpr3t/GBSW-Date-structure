#include <stdio.h>

#define STACK_SIZE 10

int stack[STACK_SIZE];
int top = -1;

int isFull() {
    if (top >= STACK_SIZE) {
        printf("Error: Stack is Full!\n");
        return 1;
    }
    return 0;
}

int Full(int count) {
    if (top + count > STACK_SIZE) {
        printf("Error: Stack is Full!\n");
        return 0;
    }
    return 1;
}

void push() {
    int count = 0, temp = 0;
    if (!isFull()) {
        printf("넣고자 하는 숫자 개수를 입력하세요: ");
        scanf("%d", &count);
        if (Full(count)){
            printf("숫자를 입력하세요: ");
            for (int i = 0; i < count; i++) {
                scanf("%d", &temp);
                stack[++top] = temp;
            }
        }
    }
}

int isEmpty() {
    if (top == -1) {
        printf("Error: Stack is Empty!\n");
        return 1;
    }
    return 0;
}

void pop() {
    if (isEmpty()) {
        printf("Error: Stack is Empty!\n");
    } else {
        stack[--top];
    }
}

void print_stack() {
    printf("\n");
    for (int i = 0; i <= top; ++i) {
        printf("%d\n", stack[i]);
    }
    printf("\n");
}

int exit_() {
    return 0;
}

int main() {
    int select = 0;
    while (select != 4) {
        printf("-----------------------------------------------------\n");
        printf("실행하고 싶은 숫자를 입력하세요\n");
        printf("1. 삽입\n"
               "2. 삭제\n"
               "3. 출력\n"
               "4. 종료\n");
        scanf("%d", &select);
        switch (select) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                print_stack();
                break;
            case 4:
                exit_();
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    }
    return 0;
}
