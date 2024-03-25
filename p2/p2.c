#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* push_back(struct ListNode* l, int num) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    if (node == NULL) {
        exit(1);
    }

    node->val = num;
    node->next = NULL;

    struct ListNode* cursor = l;

    if (!l) { 
        l = node; 
    } else {
        while (cursor->next) {
            cursor = cursor->next;
        }

        cursor->next = node;
    }

    return l;
}

struct ListNode* reverse_list(struct ListNode* l) {
    if (l->next == NULL) { return l; }

    struct ListNode* current = l;
    struct ListNode* next = current->next;
    struct ListNode* prev = current;

    while (next) {
        current = next;
        next = next->next;

        current->next = prev;
        prev = current;
    }

    l->next = NULL;
    return current;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* res = NULL;

    int carry = 0;

    while (l1 || l2) {
        int sum = carry;

        if (l1 && l2) {
            sum += l1->val + l2->val;

            l1 = l1->next;
            l2 = l2->next;

        } else if (!l1 && l2) {
            sum += l2->val;

            l2 = l2->next;

        } else {
            sum += l1->val;

            l1 = l1->next;

        }

        res = push_back(res, sum % 10);

        carry = sum / 10;

    }

    if (carry != 0) {
        res = push_back(res, carry);
    }

    return res;
}
