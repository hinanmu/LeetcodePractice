/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int flag = 0;
        sudoku(board, 0, flag);
    }

    void sudoku(vector<vector<char>>& board, int idx, int& flag)
    {
        if(idx == 81) {
            flag = 1;
            return;
        }

        int col = idx % 9;
        int row = idx / 9;

        if (board[row][col] != '.')
        {
            sudoku(board, idx + 1, flag);
        }else
        {
            vector<int> val(9);
            for (int i = 0; i < 9 ; i++)
            {
                if (board[i][col] != '.')
                {
                    val[board[i][col] - '1'] = 1;
                }
            }

            for (int i = 0; i < 9 ; i++)
            {
                if (board[row][i] != '.')
                {
                    val[board[row][i] - '1'] = 1;
                }
            }

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int c = col - col % 3 + i;
                    int r = row - row % 3 + j;
                    if (board[r][c] != '.')
                    {
                        val[board[r][c] - '1'] = 1;
                    }
                }
            }

            for (int i = 0; i < 9 ; i++)
            {
                if (val[i] == 0)
                {
                    board[row][col] = i + '1';
                    sudoku(board, idx + 1, flag);
                    if (flag == 1)
                    {
                        return;
                    }
                }
            }
            board[row][col] = '.';

        }
    }
};


