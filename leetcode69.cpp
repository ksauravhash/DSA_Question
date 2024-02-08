/**
 * https://leetcode.com/problems/sqrtx/
 */

class Solution
{
public:
    int mySqrt(int x)
    {
        int start = 0;
        int end = x;
        long long int mid = start + (end - start) / 2;
        int ans = 0;
        while (start <= end)
        {
            long long int square = mid * mid;
            // If it's square is greater than the number
            if (square > x)
                end = mid - 1;
            else
            {
                ans = mid;
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
};