/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int result = 1;
        if(n > m)
        {
            int temp = n;
            n = m;
            m = temp;
        }
        n = n - 1;
        m = m - 1;
        int temp = 1;
        for (int i = 0; i < n; i++)
        {
            result *= n + m - i;
            if(result % ((n - i)*temp) == 0)
            {
                result /= ((n - i)*temp);
                temp = 1;
            }
            else
            {
                int v = get(result, (n - i)*temp);
                if (v != 1)
                {
                    result /= v;
                    temp = (n - i)*temp / v;
                }
                else
                {
                    temp *= (n - i);  
                }
                
            }
            
        }
        return result;
    }
    
    int get(int a, int b)
    {
        while(a != b)
        {
            if(a < b)
            {
                int temp = a;
                a = b;
                b = temp;
            }
            a = a - b;
        }
        return a;
    }
};

