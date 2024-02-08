/**
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
 */

#include <vector>

class Solution
{
public:
    int peakIndexInMountainArray(std::vector<int> &arr)
    {
        int start = 0;
        int end = arr.size() - 1;
        int mid = start + (end - start) / 2;
        while (start < end)
        {

            // If the element is on the left side of the mountain
            if (arr[mid] < arr[mid + 1])
                start = mid + 1;
            else // If the element is on the right side or is the peak of the mountain
                end = mid;
            mid = start + (end - start) / 2;
        }
        return start;
    }
};