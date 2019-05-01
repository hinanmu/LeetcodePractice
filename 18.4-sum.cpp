/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (nums.size() < 4) return {};
        for(int m = 0; m < (nums.size() - 3); m++) {
            for(int i = m+1; i < (nums.size() - 2); i++)
            {
                int j = i + 1;
                int k = nums.size() - 1;
                while(j < k)
                {
                    int sum = nums[m] + nums[i] + nums[j] + nums[k];
                    if(sum == target)
                    {
                        vector<int> temp;
                        temp.push_back(nums[m]);
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        result.push_back(temp);
                        int l = nums[j];
                        int r = nums[k];
                        while(l == nums[j] && j < k)
                        {
                            j++;
                        }
                        while(r == nums[k] && j < k)
                        {
                            k--;
                        }

                    }
                    else if(sum < target)
                    {
                        j++;
                    }
                    else if(sum > target)
                    {
                        k--;
                    }
                }

                while(i < nums.size() - 2)
                {
                    if(nums[i] == nums[i+1])
                    {
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            
             while(m < nums.size() - 2)
            {
                if(nums[m] == nums[m+1])
                {
                    m++;
                }
                else
                {
                    break;
                }
            }
        }

        return result; 
    }
};
