/**
 * @brief https://leetcode.com/problems/add-two-numbers/
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 *
 *
 * Definition for singly-linked list.
 * struct ListNode
 {
     *int val;
     *struct ListNode *next;
     *
 };
 */

#include <stdlib.h>
#include <math.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    long long unsigned l1Sum = 0;
    long long unsigned l2Sum = 0;
    long long unsigned l3Sum = 0;
    long double pos = 0;
    struct ListNode *ptr = l1;
    long long unsigned i = 0;
    while (ptr != NULL)
    {
        pos = pow(10, i);
        l1Sum = l1Sum + (ptr->val * (pos));
    printf("%d l1sum is \r\n",l1Sum);

        ptr = ptr->next;
        i++;
    }
  if (i>1 && l1Sum ==1)
    {
        l1Sum=pow(10,i) + 1;
    }

    ptr = l2;

    i = 0;
    while (ptr != NULL)
    {
        pos = pow(10, i);
        l2Sum = l2Sum + (ptr->val * (pos));
        ptr = ptr->next;
        i++;
    }



    l3Sum = l1Sum + l2Sum;
    long long unsigned l3SumRev = 0;
    i = 0;
    while (l3Sum)
    {
        pos = pow(10, i);
        l3SumRev = l3SumRev + ((l3Sum % 10) * (pos));
        l3Sum /= 10;
        i++;
    }

    struct ListNode *l3 = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
    l3->next = NULL;
    l3->val = 0;
    ptr = l3;
    while (l3SumRev)
    {
        ptr->val = l3SumRev % 10;
        l3SumRev /= 10;
        if (l3SumRev)
        {
            ptr->next = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
            ptr = ptr->next;
        }
        else
        {
            ptr->next = NULL;
        }
    }

    return l3;
}

void main()
{

    struct ListNode *l1 = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
    l1->val = 2;
    l1->next = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    struct ListNode *l2 = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
    l2->val = 5;
    l2->next = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    addTwoNumbers(l1, l2);
}