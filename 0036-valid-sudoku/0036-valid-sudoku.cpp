class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {};

        // col[j][num] = whether num exists in column j
        bool col[9][9] = {};

        // box[k][num] = whether num exists in box k
        bool box[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Ignore empty cells
                if (board[i][j] == '.')
                    continue;

                // Convert '1'...'9' -> 0...'8'
                int num = board[i][j] - '1';

                // Find the 3x3 box
                int k = (i / 3) * 3 + (j / 3);

                // Duplicate found
                if (row[i][num] ||
                    col[j][num] ||
                    box[k][num]) {
                    return false;
                }

                // Mark the number as seen
                row[i][num] = true;
                col[j][num] = true;
                box[k][num] = true;
            }
        }

        return true;
    }
    
};