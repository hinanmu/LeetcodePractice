/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i = 0;
        int j = nums.size() - 1;
        int repeat = 0;
        while (i <= j)
        {
            if (nums[i] == val && nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
                j--;
                repeat += 1;
            }
            else if (nums[i] == val && nums[j] == val)
            {
                j--;
                repeat += 1;
            }
            else
            {
                i++;
            }
        }
        return nums.size() - repeat;
    }
};

