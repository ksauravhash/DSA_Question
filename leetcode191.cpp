/**
 * https://leetcode.com/problems/number-of-1-bits/description/
 */

#include <cstdint>
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n != 0)
        {
            if (n % 2)
            {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};