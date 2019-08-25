/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int flag = 1;
        int round = n;
        int row = 0;
        int cnt = 0;
        int value = 1;
        vector<vector<int>> result;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            result.push_back(v);
        }
        while(round >= 1)
        {
            if(flag == 1)
            {
                for (int i = 0; i < round; i++)
                {
                    result[row][cnt+i] = value;
                    value++;
                }
                row++;
                cnt = cnt + round - 1;
                
                for(int i = 0; i < round - 1; i++)
                {
                    result[row+i][cnt] = value;
                    value++;
                }
                row = row + round - 2;
                cnt--;
                round--;
                flag = 0;
            }
            else
            {
                for (int i = 0; i < round; i++)
                {
                    result[row][cnt - i] = value;
                    value++;
                }
                row--;
                cnt = cnt - (round - 1);
                for(int i = 0; i < round - 1; i++)
                {
                    result[row-i][cnt] = value;
                    value++;
                }
                row = row - (round - 2);
                cnt++;
                round--;
                flag = 1;
            }
        }
        return result;
    }
};

