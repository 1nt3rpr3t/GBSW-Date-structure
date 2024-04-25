#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *link;
} ListNode;

ListNode *head = NULL;
ListNode *tail = NULL;

int add() {
    int numCount, temp;
    printf("넣고자 하는 숫자 개수를 입력하시오: ");
    scanf("%d", &numCount);
    printf("숫자를 입력하세요: ");
    for (int i = 0; i < numCount; ++i) {
        scanf("%d", &temp);
        ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
        newNode -> data = temp;
        newNode -> link = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            tail -> link = newNode;
        }
        tail = newNode;
    }
    return 0;
}

int insert() {
    int location, temp;
    printf("추가하려는 위치를 입력하세요:");
    scanf("%d", &location);
    printf("추가하고싶은 수를 입력하세요:");
    scanf("%d", &temp);

    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    newNode -> data = temp;
    newNode -> link = NULL;

    for (ListNode *pt = head; pt != NULL; pt = pt->link) {
        if (pt -> data == location) {
            newNode -> link = pt -> link;
            pt -> link = newNode;
        }
    }
    return 0;
}

int del() {
    int temp;
    printf("삭제하고 싶은 데이터를 입력하세요: ");
    scanf("%d", &temp);
    for (ListNode *pt = head; pt != NULL; pt = pt->link) {
        if (head -> data == temp) {
            head = head -> link;
        }
        if (pt -> link -> data == temp) {
            pt -> link = pt -> link -> link;
            break;
        }
    }
    return 0;
}

int print() {
    for (ListNode *pt = head; pt != NULL; pt = pt->link) {
        printf("%d->", pt->data);
    }
    printf("NULL\n");
    return 0;
}

int exit_() {
    return 0;
}

int main() {
    int select = 0;
    while (select != 5) {
        printf("-----------------------------------------------------\n");
        printf("실행하고 싶은 숫자를 입력하세요\n");
        printf("1. 추가\n"
               "2. 삽입\n"
               "3. 삭제\n"
               "4. 출력\n"
               "5. 종료\n");
        scanf("%d", &select);
        switch (select) {
            case 1:
                add();
                break;
            case 2:
                insert();
                break;
            case 3:
                del();
                break;
            case 4:
                print();
                break;
            case 5:
                exit_();
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    }
    return 0;
}
