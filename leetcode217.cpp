/**
 * https://leetcode.com/problems/contains-duplicate/
 */

#include <unordered_map>
#include <vector>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_map<int, int> map;
        for (auto item : nums)
        {
            map[item]++;
        }
        for (auto item : map)
        {
            if (item.second > 1)
                return true;
        }
        return false;
    }
};