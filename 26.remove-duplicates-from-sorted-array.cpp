/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        
        int i = 0;
        int j = i + 1;
        while (j < nums.size())
        {   
            if (nums[j] == nums[i])
            {
                j++;
            }
            else
            {
                i++;
                nums[i] = nums[j];
                j++;
            }
            
        }
        
    return i + 1;
    }
};

