/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        vector<ListNode*> v1(lists.begin(), lists.begin() + lists.size() / 2);
        vector<ListNode*> v2(lists.begin()+lists.size() / 2, lists.end());
        
        ListNode* l1 =  mergeKLists(v1);
        ListNode* l2 =  mergeKLists(v2);
        
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }

        ListNode* result = l1;
        if(l1->val > l2->val) {
            l1 = l2;
            l2 = result;
            result = l1;
        }
        while(l1->next != NULL && l2 != NULL) {
            if(l1->next->val > l2->val) {
                ListNode* temp = l2;
                while(temp->next != NULL) {
                    if(temp->next->val > l1->next->val) {
                        break;
                    }
                    temp = temp->next;
                }
                ListNode* temp1 = temp->next;
                temp->next = l1->next;
                l1->next = l2;
                l1 = temp->next;
                l2 = temp1;
            }else{
                l1 = l1->next;
            }
        }
        if(l2 != NULL) {
            l1->next = l2;
        }

        return result;
    }
};

