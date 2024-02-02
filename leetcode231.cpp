/**
 * https://leetcode.com/problems/power-of-two/
 */

#include <climits>
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int num = 1;
        if (n == 1)
            return true;
        while (n > num)
        {
            if (num < INT_MAX / 2)
                num = num << 1;
            else
                break;
            if (num == n)
                return true;
        }
        return false;
    }
};