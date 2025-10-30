# include <vector>

using namespace std;

class Solution {
public:
    int getGridId(int i, int j) {
        return i / 3 * 3 + j / 3;
    }

    bool dfs(
        int depth, 
        vector<int>& row,
        vector<int>& col,
        vector<int>& grid,
        vector<vector<char>>& board
    ) {
        if (depth == 81)
            return true;

        if (board[depth / 9][depth % 9] != '.')
            return dfs(depth + 1, row, col, grid, board);

        int& row_ij = row[depth / 9];
        int& col_ij = col[depth % 9];
        int& grid_ij = grid[getGridId(depth / 9, depth % 9)];

        for (int elem = 1; elem <= 9; ++elem) {
            if (
                ((row_ij & (1 << elem)) != 0)
                || ((col_ij & (1 << elem)) != 0)
                || ((grid_ij & (1 << elem)) != 0)
            )
                continue;
            board[depth / 9][depth % 9] = '0' + elem;
            row_ij |= (1 << elem);
            col_ij |= (1 << elem);
            grid_ij |= (1 << elem);

            bool res = dfs(depth + 1, row, col, grid, board);
            if (res)    return true;
    
            board[depth / 9][depth % 9] = '.';
            row_ij &= ~(1 << elem);
            col_ij &= ~(1 << elem);
            grid_ij &= ~(1 << elem);
        }
    
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        vector<int> row(9, 0), col(9, 0), grid(9, 0);

        // Initialize Set 
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';
                row[i] |= (1 << num);
                col[j] |= (1 << num);
                grid[getGridId(i, j)] |= (1 << num);
            }
        }

        dfs(0, row, col, grid, board);

        return ;
    }
};