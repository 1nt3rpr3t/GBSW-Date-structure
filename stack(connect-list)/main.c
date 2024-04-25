#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *link;
} ListNode;

ListNode *head = NULL;
ListNode *top = NULL;

void add() {
    int temp;
    printf("숫자를 입력하세요: ");
    scanf("%d", &temp);
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    newNode->data = temp;
    newNode->link = NULL;

    if (head == NULL) {
        head = newNode;
        top = newNode;
    } else {
        top->link = newNode;
        newNode->link = NULL;
    }
    top = newNode;
}

void pop() {
    for (ListNode *pt = head; pt != NULL; pt = pt->link) {
        if (pt->link->link == NULL) {
            pt->link = NULL;
            top = pt;
            break;
        }
    }
}

void print() {
    for (ListNode *pt = head; pt != NULL; pt = pt->link) {
        printf("%d->", pt->data);
    }
    printf("NULL\n");
}

int exit_() {
    return 0;
}

int main() {
    int select = 0;
    while (select != 4) {
        printf("-----------------------------------------------------\n");
        printf("실행하고 싶은 숫자를 입력하세요\n");
        printf("1. 추가\n"
               "2. 삭제\n"
               "3. 출력\n"
               "4. 종료\n");
        scanf("%d", &select);
        switch (select) {
            case 1:
                add();
                break;
            case 2:
                pop();
                break;
            case 3:
                print();
                break;
            case 4:
                exit_();
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    }
}
