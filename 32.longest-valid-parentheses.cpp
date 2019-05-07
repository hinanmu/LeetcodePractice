/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1)
        {
            return 0;
        }
        
        vector<int> dp(s.size());
        stack<char> st;
        stack<char> idx;
        int max = 0;
        st.push(s[0]);
        idx.push(0);
        for (int i = 1; i < s.size(); i++)
        {
             if (!st.empty() && st.top() == '(' && s[i] == ')')
            {
                dp[idx.top()] = 1;
                dp[i] = 1;
                st.pop();
                idx.pop();
            }
            else
            {
                st.push(s[i]);
                idx.push(i);
            }       

        }
        int temp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (dp[i] == 0)
            {
                temp = 0;
            }
            else
            {
                temp += dp[i];
            }

            if (temp > max)
            {
                max = temp;
            }
        }
        return max;
        
    }
};

