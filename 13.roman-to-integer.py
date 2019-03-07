#
# @lc app=leetcode id=13 lang=python3
#
# [13] Roman to Integer
#
# https://leetcode.com/problems/roman-to-integer/description/
#
# algorithms
# Easy (51.55%)
# Total Accepted:    369.4K
# Total Submissions: 716K
# Testcase Example:  '"III"'
#
# Roman numerals are represented by seven different symbols: I, V, X, L, C, D
# and M.
# 
# 
# Symbol       Value
# I             1
# V             5
# X             10
# L             50
# C             100
# D             500
# M             1000
# 
# For example, two is written as II in Roman numeral, just two one's added
# together. Twelve is written as, XII, which is simply X + II. The number
# twenty seven is written as XXVII, which is XX + V + II.
# 
# Roman numerals are usually written largest to smallest from left to right.
# However, the numeral for four is not IIII. Instead, the number four is
# written as IV. Because the one is before the five we subtract it making four.
# The same principle applies to the number nine, which is written as IX. There
# are six instances where subtraction is used:
# 
# 
# I can be placed before V (5) and X (10) to make 4 and 9. 
# X can be placed before L (50) and C (100) to make 40 and 90. 
# C can be placed before D (500) and M (1000) to make 400 and 900.
# 
# 
# Given a roman numeral, convert it to an integer. Input is guaranteed to be
# within the range from 1 to 3999.
# 
# Example 1:
# 
# 
# Input: "III"
# Output: 3
# 
# Example 2:
# 
# 
# Input: "IV"
# Output: 4
# 
# Example 3:
# 
# 
# Input: "IX"
# Output: 9
# 
# Example 4:
# 
# 
# Input: "LVIII"
# Output: 58
# Explanation: L = 50, V= 5, III = 3.
# 
# 
# Example 5:
# 
# 
# Input: "MCMXCIV"
# Output: 1994
# Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
# 
#
class Solution:
    def romanToInt(self, s: str) -> int:
        num  = 0
        temp= 0
        for val in s:
            if val == 'I' :
                temp = 1
            elif val == 'V':
                if temp == 1:
                    temp = 3
                else:
                    temp = 5
            elif val == 'X':
                if temp == 1:
                    temp = 8
                else:
                    temp = 10
            elif val == 'L':
                if temp == 10:
                    temp = 30
                else:
                    temp = 50
            elif val == 'C':
                if temp == 10:
                    temp = 80
                else:
                    temp = 100
            elif val == 'D':
                if temp == 100:
                    temp = 300
                else:
                    temp = 500
            elif val == 'M':
                if temp == 100:
                    temp = 800
                else:
                    temp = 1000
            num += temp
        return num
        

