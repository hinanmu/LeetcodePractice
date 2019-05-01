/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generate(0, 0, "", n);
        return result;
    }
    
    int generate(int left,int right,string s,int n)
    {
        if(left==n && right == n)
        {
            result.push_back(s);
        }
        else
        {
            int l = left;
            if(left < n)
            {
                generate(++left, right, s + "(", n);
            }
            if(l > right)
            {
                generate(l, ++right, s + ")", n);
            }
        }
        return 0;
    }
private: 
    vector<string> result;
};