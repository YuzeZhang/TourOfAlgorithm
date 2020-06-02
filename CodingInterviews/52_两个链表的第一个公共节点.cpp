//
// Created by Zeno on 2020/6/2.
//

/*
 * 思路：
 * 双指针分别遍历两个链表，若第一个指针到达尾端，则将其挪到第二个链表的头部
 * 若第二个指针到达尾端，则将其挪到第一个链表的头部
 * time complexity:O(n)
 * space complexity:O(1)
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* curA = headA;
    ListNode* curB = headB;
    while (curA != curB) {
        curA = curA != nullptr ? curA->next : headB;
        curB = curB != nullptr ? curB->next : headA;
    }
    return curA;
}