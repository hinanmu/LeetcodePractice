/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> ans;
        backtrack(result, ans, k, n, 0);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& ans, int k, int n, int pos) 
    {
        if (k == 0 && n == 0)
        {
            result.push_back(ans);
            return;
        }
        else if (k == 0)
        {
            return;
        }
        
        for (int i = pos + 1; i <= 9; i++)
        {
            ans.push_back(i);
            backtrack(result, ans, k-1, n-i, i);
            ans.pop_back();
        }
        
    }
};

