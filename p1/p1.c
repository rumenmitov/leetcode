#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };

int* getNum(struct ListNode* list);
int* revArr(int* arr, int size);
int addNums(int* num1, int size1, int* num2, int size2);
int getSize(struct ListNode* list);
struct ListNode* parseNum_rev(int num);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
int main(void) {

    struct ListNode* myList = (struct ListNode*) malloc(sizeof(struct ListNode));

    myList->val = 2;
    myList->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    (myList->next)->val = 2;
    
    struct ListNode* myList2 = (struct ListNode*) malloc(sizeof(struct ListNode));

    myList2->val = 3;
    myList2->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    (myList2->next)->val = 2;

    struct ListNode* res = addTwoNumbers(myList, myList2);
    printf("add nums 1: %d\n", res->val);
    printf("add nums 2: %d\n", res->next->val);

    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int* num1 = getNum(l1);
    int size1 = getSize(l1);
    int* num2 = getNum(l2);
    int size2 = getSize(l2);

    int sum = addNums(num1, size1, num2, size2);
    struct ListNode* res = parseNum_rev(sum);


    return res;
}

int* getNum(struct ListNode* list) {
    int* arr = (int*) malloc(sizeof(int));

    struct ListNode* ptr = list;

    int i = 0;
    do {
        i++;
        arr[i-1] = ptr->val;
        arr = realloc(arr, sizeof(int) * (i+1));
        ptr = ptr->next;
    } while (ptr);
   
    arr = realloc(arr, sizeof(int) * i);

    return revArr(arr, i);

}

int* revArr(int* arr, int size) {
    int* res = (int*) malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        res[i] = arr[size - 1 - i];
    }

    free(arr);
    arr = NULL;

    return res;
}

int getSize(struct ListNode* list) {
    int ans = 0;

    struct ListNode* ptr = list;

    while (ptr) {
        ++ans;
        ptr = ptr->next;
    }

    return ans;
}

int addNums(int* num1, int size1, int* num2, int size2) {
    int num1_parsed = 0;
    int num2_parsed = 0;

    for (int i = size1-1; i >= 0; --i) {
        num1_parsed += num1[i] * pow(10, i);
    }

    for (int i = size2-1; i >= 0; --i) {
        num2_parsed += num2[i] * pow(10, i);
    }

    free(num1);
    num1 = NULL;

    free(num2);
    num2 = NULL;

    return num1_parsed + num2_parsed;
}

struct ListNode* parseNum_rev(int num) {
    struct ListNode* res = (struct ListNode*) malloc(sizeof(struct ListNode));

    struct ListNode* ptr = res;
    while (num) {
        int rem = num % 10;

        ptr->val = rem;
        num = (num - rem) / 10;

        if (num) {
            ptr->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            ptr = ptr->next;
        } else {
            ptr->next = NULL;
        }
    }
    
    return res;
}
