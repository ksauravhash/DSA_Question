/**
 * https://leetcode.com/problems/unique-number-of-occurrences/description/
 */

#include <unordered_map>
#include <vector>
class Solution
{
public:
    bool uniqueOccurrences(std::vector<int> &arr)
    {
        std::unordered_map<int, int> map;
        std::unordered_map<int, int> map2;
        for (int i = 0; i < arr.size(); i++)
        {
            map[arr[i]]++;
        }
        for (auto item : map)
        {
            map2[item.second]++;
        }
        for (auto item2 : map2)
        {
            if (item2.second > 1)
                return false;
        }
        return true;
    }
};