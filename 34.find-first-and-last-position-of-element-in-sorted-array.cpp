/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    vector<int> result;
    int flag = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {

            if (mid == 0 && flag == 0)
            {
                result.push_back(mid);
                flag = 1;
                if (result.size() == 2)
                {
                    break;
                }
                else
                {
                    l = mid;
                    r = nums.size() - 1;
                    continue;
                }
            }
            else if (mid > 0 && nums[mid - 1] < target && flag == 0)
            {
                result.push_back(mid);
                flag = 1;
                if (result.size() == 2)
                {
                    break;
                }
                else
                {
                    l = mid;
                    r = nums.size() - 1;
                    continue;
                }
            }
            else if (mid == nums.size() - 1)
            {
                result.push_back(mid);
                if (result.size() == 2)
                {
                    break;
                }
                else
                {
                    l = 0;
                    r = mid;
                    continue;
                }
            }
            else if (mid < nums.size() - 1 && nums[mid + 1] > target)
            {
                result.push_back(mid);
                if (result.size() == 2)
                {
                    break;
                }
                else
                {
                    l = 0;
                    r = mid;
                    continue;
                }
            }

            if (flag == 0)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }

        }
        else if(nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (result.size() == 0)
    {
        result.push_back(-1);
        result.push_back(-1);
    }
    if (result[0] > result[1])
    {
        int temp = result[0];
        result[0] = result[1];
        result[1] = temp;
    }
        return result;
    }
};

