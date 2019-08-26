/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int result = 0;
        if (height.size() <= 2)
        {
            return 0;
        }
        s.push(0);
        for (int i = 1; i < height.size(); i++)
        {
            int h = s.top();
            if (height[i] > height[h])
            {
                if(s.size() == 1)
                {
                    s.pop();
                    s.push(i);
                }
                else
                {
                    s.pop();
                    result += min(height[s.top()]-height[h], height[i]-height[h]) * (i-s.top()-1);
                    if (height[s.top()] > height[i])
                    {
                        s.push(i);
                    }                
                    else
                    {
                        i--;
                    }
                    
                }
            }
            else
            {
                s.push(i);
            }
            
        }
        return result;
        
    }
};
