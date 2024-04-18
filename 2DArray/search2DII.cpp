/*
* Leetcode 240
* https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        // Top right corner
        int rowIndex = 0;
        int colIndex = matrix[0].size()-1;
        while(rowIndex < row && colIndex >= 0) {
            int element = matrix[rowIndex][colIndex];
            if(element == target)
                return true;
            else if(element < target) 
                rowIndex++;
            else 
                colIndex--;
        }
        return false;
    }
};