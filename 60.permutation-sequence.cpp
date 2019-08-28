/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
        string v = "";
        for (int i = 0; i < n; i++)
        {
            char c = '0' + i + 1;
            v = v + c;
        }
        
        bt(k, result, v);
        return result;
    }

    void bt(int k, string & result, string v)
    {
        int count = 1;
        
        int num = v.size();
        while (result.size() < num)
        {
            int n = v.size();
            for (int i = 1; i <= n; i++)
            {
                
                if (count * i >= k)
                {
                    if(count * i == k)
                    {
                        
                        for (int j = 1; j <= n; j++)
                        {
                            if(j <= n-i)
                            {
                                result = result + v[j-1];
                            }
                            else
                            {
                                result = result + v[n-j];
                            }   
                        }
                        break;
                    }
                    int temp = (k-1) / count;
                    k = k % count;
                    for (int j = 1; j <= n - i; j++)
                    {
                        result = result + v[j-1];
                    }
                    v = v.substr(n-i);
                    result = result + v[temp];
                    v.erase(temp, 1);
                    break;
                    
                }
                else
                {
                    count *= i;
                }  
                
            }
            count = 1;
        }
    }
};


