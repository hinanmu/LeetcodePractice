#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#
# https://leetcode.com/problems/longest-palindromic-substring/description/
#
# algorithms
# Medium (26.59%)
# Total Accepted:    482K
# Total Submissions: 1.8M
# Testcase Example:  '"babad"'
#
# Given a string s, find the longest palindromic substring in s. You may assume
# that the maximum length of s is 1000.
# 
# Example 1:
# 
# 
# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
# 
# 
# Example 2:
# 
# 
# Input: "cbbd"
# Output: "bb"
# 
# 
#
class Solution:
    def longestPalindrome(self, s: str) -> str:
        index = 0
        max_len = 0
        k = 0
        for i in range(len(s)):

            for m in range(len(s) - i):
                j = len(s) - 1 - m
                length = 0
                k = i
                if (j - i) < max_len:
                    continue
                while (k <= j):
                    if s[k] == s[j] and k != j:
                        length += 2
                        k += 1
                        j -= 1
                    elif s[k] == s[j] and k == j:
                        length += 1
                        k += 1
                        j -= 1
                    else:
                        length = 1
                        break
                if length > max_len:
                    index = i
                    max_len = length

        return s[index:index + max_len]

