/**
 * https://leetcode.com/problems/intersection-of-two-arrays/
 */

#include <vector>
#include <set>
#include <climits>
class Solution
{
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> ans;
        std::set<int> prevAns;
        for (int i = 0; i < nums1.size(); i++)
        {
            int element = nums1[i];
            for (int j = 0; j < nums2.size(); j++)
            {
                if (element == nums2[j])
                {
                    prevAns.insert(element);
                    nums2[j] = INT_MIN;
                    break;
                }
            }
        }
        for (auto i : prevAns)
        {
            ans.push_back(i);
        }
        return ans;
    }
};