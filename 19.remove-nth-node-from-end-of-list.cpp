/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;
        ListNode* l = head;
        ListNode* m = head;
        while (m != NULL)
        {
            if (num == n+1)
            {
                m = m->next;
                l = l->next;
            }
            else
            {
                num++;
                m = m->next;
            }
        }

        if (num == n)
        {
            return head->next;
        }
        else
        {
            l->next = l->next->next;
        }
        
        return head;
    }
};
