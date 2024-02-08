/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 */
#include <vector>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        // First find the pivot index
        int start = 0;
        int n = nums.size() - 1;
        int end = n;
        int mid = start + (end - start) / 2;
        int pivot;
        while (start < end)
        {
            if (nums[mid] >= nums[0])
                start = mid + 1;
            else
                end = mid;
            mid = start + (end - start) / 2;
        }
        pivot = start;
        // If it is on the 2nd side
        if (nums[pivot] <= target && target <= nums[n])
        {
            start = pivot;
            end = n;
        }
        else
        {
            start = 0;
            end = pivot - 1;
        }
        // Binary search
        mid = start + (end - start) / 2;
        while (start <= end)
        {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
            mid = start + (end - start) / 2;
        }
        return -1;
    }
};