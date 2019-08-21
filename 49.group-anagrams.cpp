/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> m;
        vector<vector<string>> result;
        int groupId = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            int cnt = m.count(temp);
            if(cnt > 0)
            {
                result[m[temp]].push_back(strs[i]);
            }
            else
            {
                m[temp] = groupId;
                groupId++;
                vector<string> tempStr;
                tempStr.push_back(strs[i]);
                result.push_back(tempStr);
            }
            
        }
        return result;
        
    }
};
