#
# @lc app=leetcode id=7 lang=python
#
# [7] Reverse Integer
#
# https://leetcode.com/problems/reverse-integer/description/
#
# algorithms
# Easy (25.12%)
# Total Accepted:    612.1K
# Total Submissions: 2.4M
# Testcase Example:  '123'
#
# Given a 32-bit signed integer, reverse digits of an integer.
# 
# Example 1:
# 
# 
# Input: 123
# Output: 321
# 
# 
# Example 2:
# 
# 
# Input: -123
# Output: -321
# 
# 
# Example 3:
# 
# 
# Input: 120
# Output: 21
# 
# 
# Note:
# Assume we are dealing with an environment which could only store integers
# within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
# this problem, assume that your function returns 0 when the reversed integer
# overflows.
# 
#
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        list = []
        flag = 1
        if x < 0:
            flag = 0
            x = -x
        while(x != 0):
            list.append(x % 10)
            x = int(x / 10)
        for val in list:
            x = x * 10 + val
        if flag == 0:
            x = -x
        if x < -2**31 or x >= 2**31:
            x = 0
        return x 

