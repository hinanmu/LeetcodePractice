/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp;
        for (int i = 0; i < matrix.size(); i++)
        {
            vector<int> vec;
            for (int j = matrix.size() - 1; j >= i; j--)
            {
                vec.push_back(matrix[j][i]);
            }
            for (int j = temp.size() - 1; j >= 0; j--)
            {
                vec.push_back(temp[j][i]);
            }
            temp.push_back(matrix[i]);
            matrix[i] = vec;            
        }
    }
};

