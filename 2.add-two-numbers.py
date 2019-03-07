#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#
# https://leetcode.com/problems/add-two-numbers/description/
#
# algorithms
# Medium (30.58%)
# Total Accepted:    777.6K
# Total Submissions: 2.5M
# Testcase Example:  '[2,4,3]\n[5,6,4]'
#
# You are given two non-empty linked lists representing two non-negative
# integers. The digits are stored in reverse order and each of their nodes
# contain a single digit. Add the two numbers and return it as a linked list.
# 
# You may assume the two numbers do not contain any leading zero, except the
# number 0 itself.
# 
# Example:
# 
# 
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.
# 
# 
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        result = ListNode(0)
        temp = result
        a = 0
        while l1 != None and l2 != None:
            b = (l1.val + l2.val + a) % 10
            result.next = ListNode(b)
            a = (l1.val + l2.val + a) // 10
            l1 = l1.next
            l2 = l2.next
            result = result.next
        
        if l1 == None:
            l1 = l2
        while l1 != None:
            b = (l1.val + a) % 10
            result.next = ListNode(b)
            a = (l1.val + a) // 10
            result = result.next
            l1 = l1.next
            
        if a != 0:
            result.next = ListNode(a)
        return temp.next

