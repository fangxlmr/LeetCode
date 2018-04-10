/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */


#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode        //链表节点结构
{
    int val;
    struct ListNode *next;
}ListNode, *pListNode;

struct ListNode* addTwoNumbers(pListNode, pListNode);
int check(pListNode);


int main()
{
    int nums1[]={2, 4, 3, 9}, nums2[]={5, 6, 4, 7};
    int len1 = sizeof(nums1)/sizeof(int), len2 = sizeof(nums2)/sizeof(int);
    printf("len1 = %1d, len2 = %d\n", len1, len2);

    pListNode l1, pCur1, l2, pCur2;   // 定义两个链表
    pCur1 = l1 = (pListNode) malloc(sizeof(ListNode));
    pCur2 = l2 = (pListNode) malloc(sizeof(ListNode));
    pCur1->val = nums1[0];      //链表第一个元素为数组的第一个元素
    pCur2->val = nums2[0];
    int i;
    for(i = 1; i < len1; ++i){  //将数值输入链表l1
        pCur1->next = (pListNode) malloc(sizeof(ListNode));     //给新的节点分配内存
        pCur1 = pCur1->next;
        pCur1->val = nums1[i];
        pCur1->next = NULL;
    }
    for(i = 1; i < len2; ++i){  //将数值输入链表l2
        pCur2->next = (pListNode) malloc(sizeof(ListNode));
        pCur2 = pCur2->next;
        pCur2->val = nums2[i];
        pCur2->next = NULL;
    }

    pListNode pResult = addTwoNumbers(l1, l2);
    while(pResult){
        printf("%d->", pResult->val);
        pResult = pResult->next;
    }
    // pListNode pTmp;
    // pTmp = l1;
    // i = 0;
    // while(pTmp){
    //     printf("line %d: %d\n", i, pTmp->val);
    //     ++i;
    //     pTmp = pTmp->next;
    // }

    return 0;
}


pListNode addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    // typedef struct ListNode ListNode, *pListNode;
    pListNode pCur1, pCur2;          //pCur1用来循环l1, pCur2用来循环l2，pNode 作为中间节点变量
    pCur1 = l1;
    pCur2 = l2;
    pListNode L = (pListNode) malloc(sizeof(ListNode));     //新建带头结点的链表
    pListNode pNode, pTail = L;    //pNode为结点变量，pTail为指向L尾部的节点
    int carry = 0;  //carry是进位标志

    while(pCur1 || pCur2)
    {
        int x = pCur1 ? pCur1->val : 0;
        int y = pCur2 ? pCur2->val : 0;
        int sum = x+y+carry;    //每一位的结果等于两  个位数相加，再加上上一次的进位，初始进位为0
        carry = sum/10;

        pNode = (pListNode) malloc(sizeof(ListNode));   //给pNode分配下一个节点，并指向它
        pNode->val = sum % 10;   
        pTail->next = pNode;        //将表尾指向新节点
        pTail = pNode;          //将当前节点设置为新节点

        if(pCur1)
            pCur1 = pCur1->next;    //指向下一个节点
        if(pCur2)
            pCur2 = pCur2->next;
    }

    if(carry){   //当l1,l2加完时，最高位仍有进位
        pNode = (pListNode) malloc(sizeof(ListNode)); //新建结点
        pNode->val = carry;
        pTail->next = pNode;
        pTail = pNode;
    }
    pTail->next = NULL;     //当前链表结束


    pListNode pDel = L;
    L = L->next;
    free(pDel);
    return L;
}

