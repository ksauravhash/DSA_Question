/*
* Leetcode 1752
* https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
*
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for(int i = 1;i<nums.size();i++) {
          // if the current number is less than previous then it counts
            if(nums[i-1] > nums[i])
                count++;
        }
        if(nums[n-1] > nums[0])
            count++;
        // if the count <= 1 that means there is only element which is smaller than previous;
        // \      /
        //  \   /
        //   \
        return count <= 1;

    }
};