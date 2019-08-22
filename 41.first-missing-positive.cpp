/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 1  && nums[i] <= n && nums[i] != i+1 && nums[i] != nums[nums[i]-1])
            {
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i+1)
            {
                return i+1;
            }
            
        }
        return nums.size()+1;
    }
};

