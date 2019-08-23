/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low<=high)
        {
           int mid = (high - low) / 2 + low;
        
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                mid--;
                high = mid;
            }
            else
            {
                mid++;
                low = mid;
            }
        }
        return low;
    }

};

