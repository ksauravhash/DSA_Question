/*
* https://leetcode.com/problems/permutations
*/

class Solution {

    void solve(vector<vector<int>> &ans, vector<int>& nums, int index, vector<int> out) {
        if(index >= nums.size() - 1)
        {
            ans.push_back(out);
            return;
        }
        for(int i = index;i<nums.size();i++) {
            swap(out[i], out[index]);
            solve(ans, nums, index+1, out);
            swap(out[i], out[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans, nums, 0, nums);
        return ans;
    }
};