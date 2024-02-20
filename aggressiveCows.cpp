#include <iostream>
#include <vector>
#include <algorithm>

bool isPossible(std::vector<int> &v, int k, int mid)
{
    int cowCount = 1;
    int lastPos = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = v[i];
        }
    }
    return false;
}

// k is the number of cows
// v is the array of stalls
int aggressiveCows(std::vector<int> &v, int k)
{
    std::sort(v.begin(), v.end());
    int start = 0;
    int max = -1;
    int ans = -1;
    // Find the largest element
    for (auto item : v)
        max = std::max(max, item);

    int end = max;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (isPossible(v, k, mid))
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
}

int main()
{
}