/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v(nums.size());
        vector<int> vec;
        p(vec, nums, v);
        return result;
    }
    
    void p(vector<int>& vec, vector<int>& nums, vector<int>& v)
    {
        if (vec.size() == nums.size())
        {
            result.push_back(vec);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (v[i] == 1)
            {
                continue;
            }
            if (i >= 1 && nums[i-1] == nums[i] && v[i-1])
            {
                continue;
            }
            
            if (v[i] == 0)
            {
                v[i] = 1;
                vec.push_back(nums[i]);
                p(vec, nums, v);
                v[i] = 0;
                vec.pop_back();
            }
            
        }
        
    }

private:
    vector<vector<int>> result;
};

