/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
public:
    
    static bool lessSort(vector<int> a,vector<int> b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        vector<int> v(2);
        if (intervals.size() <= 1)
        {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end(), lessSort);
        
        int m = intervals[0][0];
        int n = intervals[0][1];
         for (int i = 1; i < intervals.size(); i++)
        {
             if(n >= intervals[i][0])
             {
                 n = max(n, intervals[i][1]);
             }
             else
             {
                v[0] = m;
                v[1] = n;
                result.push_back(v);
                m = intervals[i][0];
                n = intervals[i][1];
             }
         }
        v[0] = m;
        v[1] = n;
        result.push_back(v);
        return result;
    }
        
};

