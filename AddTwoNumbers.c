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
    int l1Sum = 0;
    int l2Sum = 0;
    int l3Sum = 0;

    struct ListNode *ptr = l1;
    int i=0;
    while (ptr != NULL)
    {
        l1Sum =l1Sum + (ptr->val*(int)pow(10,i));
        ptr = ptr->next;
        i++;
    }
    ptr = l2;

i=0;
    while (ptr != NULL)
    {
        l2Sum =l2Sum+ (ptr->val*pow(10,i));
        ptr = ptr->next;
        i++;
    }

    l3Sum = l1Sum + l2Sum;

    struct ListNode *l3 = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
    l3->next = NULL;
    l3->val = 0;
    ptr = l3;
    while (l3Sum)
    {
        l3->val = l3Sum % 10;
        l3Sum /= 10;
        if (l3Sum)
        {
            ptr->next = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
        }
    }
    ptr->next=NULL;

    return l3;
}



void main(){

struct ListNode *l1=(struct ListNode *) malloc(1*sizeof(struct ListNode ));
l1->val=2;
l1->next=(struct ListNode *) malloc(1*sizeof(struct ListNode ));
l1->next->val=4;
l1->next->next=(struct ListNode *) malloc(1*sizeof(struct ListNode ));
l1->next->next->val=3;
l1->next->next->next=NULL;

struct ListNode *l2=(struct ListNode *) malloc(1*sizeof(struct ListNode ));
l2->val=5;
l2->next=(struct ListNode *) malloc(1*sizeof(struct ListNode ));
l2->next->val=6;
l2->next->next=(struct ListNode *) malloc(1*sizeof(struct ListNode ));
l2->next->next->val=4;
l2->next->next->next=NULL;



addTwoNumbers(l1, l2);
}