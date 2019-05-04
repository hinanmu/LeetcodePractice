/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return;
        }
        int end = nums[nums.size() - 1];
        bool flag = 0;
        int i = nums.size() - 2;
        for (; i >= 0; i--)
        {
            if (nums[i] < nums[i+1])
            {
                flag = 1;
                break;
            }
        } 
        if(flag == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int j = nums.size() - 1; j >= 0; j--) 
        {
            if(nums[j] > nums[i]) {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;

                reverse(nums.begin()+i+1, nums.end());
                break;
            }

        }
        
    }
};

