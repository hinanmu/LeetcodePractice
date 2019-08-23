/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
class Solution {
public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        if (n == 0)
        {
            return result;
        }
        int m = matrix[0].size();
        int flag = 1;
        int row = 0;
        int cnt = 0;
        while(m > 0 && n > 0)
        {
            if (flag == 1)
            {
                if (m > 0)
                {
                    for (int i = 0; i < m; i++)
                    {
                        result.push_back(matrix[row][cnt+i]);
                    }
                    cnt = cnt + m - 1;
                    row++;
                    m--;
                }
                
                if (n > 0)
                {
                        for (int i = 0; i < n-1; i++)
                    {
                        result.push_back(matrix[row+i][cnt]);
                    }
                    row = row + n - 2;
                    cnt--;
                    n--;
                }

                flag = 0;
            }
            else
            {
                if (m > 0)
                {
                    for (int i = 0; i < m; i++)
                    {
                        result.push_back(matrix[row][cnt-i]);
                    }
                    cnt = cnt - (m - 1);
                    row--;
                    m--;
                }
                
                if (n > 0)
                {
                     for (int i = 0; i < n-1; i++)
                    {
                        result.push_back(matrix[row-i][cnt]);
                    }
                    row = row - (n - 2);
                    cnt++;  
                    n--;
                }

                flag = 1;
            }

        }
        return result;
    }
};

