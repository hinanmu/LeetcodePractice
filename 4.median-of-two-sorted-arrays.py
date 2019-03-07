#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#
# https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#
# algorithms
# Hard (25.54%)
# Total Accepted:    386.8K
# Total Submissions: 1.5M
# Testcase Example:  '[1,3]\n[2]'
#
# There are two sorted arrays nums1 and nums2 of size m and n respectively.
# 
# Find the median of the two sorted arrays. The overall run time complexity
# should be O(log (m+n)).
# 
# You may assume nums1 and nums2 cannot be both empty.
# 
# Example 1:
# 
# 
# nums1 = [1, 3]
# nums2 = [2]
# 
# The median is 2.0
# 
# 
# Example 2:
# 
# 
# nums1 = [1, 2]
# nums2 = [3, 4]
# 
# The median is (2 + 3)/2 = 2.5
# 
# 
#
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if (len(nums1) + len(nums2)) % 2 == 1:
            return self.findk(nums1, nums2, (len(nums1) + len(nums2) + 1) // 2)
        else:
            return (self.findk(nums1, nums2, (len(nums1) + len(nums2)) // 2) + self.findk(nums1, nums2, (len(nums1) + len(nums2)) // 2 + 1)) / 2
        
        
    def findk(self, nums1, nums2, k):
        l1= len(nums1)
        l2 = len(nums2)

        if l1 > l2:
            return self.findk(nums2, nums1, k)
        if l1 == 0:
            return nums2[k-1]
        if k == 1:
            return min(nums1[0], nums2[0])

        a = min(k // 2, l1)
        b = k - a
        if nums1[a - 1] < nums2[b- 1]:
            return self.findk(nums1[a:], nums2, k - a)
        elif nums1[a - 1] > nums2[b- 1]:
            return self.findk(nums1, nums2[b:], k - b)
        else:
            return nums1[a - 1]

