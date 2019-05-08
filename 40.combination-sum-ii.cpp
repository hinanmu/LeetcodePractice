/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combination(candidates, target, 0);
    }
    
    vector<vector<int>> combination(vector<int>& candidates, int target, int i) {
        int temp = 0;
        vector<vector<int>> result;
        while (i < candidates.size())
        {
            temp = target - candidates[i];
            if(temp < 0)
            {
                break;
            }

            if (temp == 0)
            {
                vector<int> cb;
                cb.push_back(candidates[i]);
                result.push_back(cb);
                return result;
            }
            else
            {
                vector<vector<int>> result_temp = combination(candidates, temp, i+1);
                for (int j = 0; j < result_temp.size(); j++)
                {
                    result_temp[j].push_back(candidates[i]);
                }
                result.insert(result.end(), result_temp.begin(), result_temp.end());
            }
            
            int val = candidates[i];
            
            while (i < candidates.size() && val == candidates[i])
            {
                i++;
            }
        }
        return result;
    }
    
};

