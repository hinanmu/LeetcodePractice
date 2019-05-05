/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] < target) {
                if (nums[r] < target && nums[mid] < nums[r])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }                
            }
            else
            {
                if(nums[l] > target && nums[l] <= nums[mid]) 
                {
                    l = mid + 1;
                } else
                {
                    r = mid - 1;
                }
                
            }
        }
        return -1;

    }

};

