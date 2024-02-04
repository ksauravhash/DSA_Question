/**
 *https://leetcode.com/problems/two-sum/
 */
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int value = (target - nums[i]);
            if (map[value] != 0)
            {

                ans.push_back(i);
                ans.push_back(map[value] - 1);
                return ans;
            }
            else
            {
                map[nums[i]] = i + 1;
            }
        }
        return ans;
    }
};