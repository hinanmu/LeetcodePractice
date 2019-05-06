/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValid(board, 0);
    }

    bool isValid(vector<vector<char>>& board, int idx)
    {
        int col = idx % 9;
        int row = idx / 9;
        int block = col / 3 + (row / 3) * 3;

        if(idx == 81) {
            return true;
        }
        if (board[row][col] == '.')
        {
            return isValid(board, idx + 1);
        }

        for (int i = 0; i < 9 ; i++)
        {
            if (board[i][col] == board[row][col]&& i != row)
            {
                return false;
            }
        }


        for (int i = 0; i < 9 ; i++)
        {
            if (board[row][i] == board[row][col]&& i != col)
            {
                return false;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int c = col - col % 3 + i;
                int r = row - row % 3 + j;
                if (board[r][c] == board[row][col] && c != col && r != row)
                {
                    return false;
                }
            }
        }

        return isValid(board, idx + 1);
    }

};