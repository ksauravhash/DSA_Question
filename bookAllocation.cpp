#include <iostream>
#include <vector>

bool isPossible(std::vector<int> &arr, int k, int mid)
{
    int count = 1;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] <= mid)
            sum += arr[i];
        else
        {
            count++;
            if (count > k || arr[i] > mid)
                return false;
            sum += arr[i];
        }
    }
    return true;
}

int bookAllocation(std::vector<int> &nums, int k)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(nums, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    std::vector<int> v = {10, 20, 30, 40, 50};
    int k = 2;
    std::cout << bookAllocation(v, k) << std::endl;
}