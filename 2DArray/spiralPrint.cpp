/*
* Leetcode 54
* https://leetcode.com/problems/spiral-matrix
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        int total = row * col;

        vector<int> ans;

        int startRow = 0, startCol = 0, endRow = row -1, endCol = col -1;
        while(count < total) {
            // Starting row
            for(int j = startCol;count < total && j<=endCol;j++) {
                ans.push_back(matrix[startRow][j]);
                count++;
            }
            startRow++;

            // Ending column
            for(int j = startRow;count < total && j<=endRow;j++) {
                ans.push_back(matrix[j][endCol]);
                count++;
            }
            endCol--;

            // Ending Row
            for(int j = endCol;count < total && j>=startCol;j--) {
                ans.push_back(matrix[endRow][j]);
                count++;
            }
            endRow--;

            // Start Column
            for(int j = endRow;count < total && j>=startRow;j--) {
                ans.push_back(matrix[j][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};