#include <iostream>
#include <vector>

int findPivotIndex(std::vector<int> v)
{
    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (v[mid] >= v[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, -1, 0};
    std::cout << findPivotIndex(arr) << std::endl;
    return 0;
}