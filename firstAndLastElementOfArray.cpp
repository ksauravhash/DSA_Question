#include <iostream>
#include <vector>

int firstOccurance(std::vector<int> &v, int key)
{
    int start = 0;
    int end = v.size() - 1;
    int ans = -1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (v[mid] == key)
        {
            // Store the answer
            ans = mid;
            // Move the end pointer back to get the left most index
            end = mid - 1;
        }
        else if (key < v[mid])
            end = mid - 1;
        else
            start = mid + 1;
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOccurance(std::vector<int> &v, int key)
{
    int start = 0;
    int end = v.size() - 1;
    int ans = -1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (v[mid] == key)
        {
            // Store the answer
            ans = mid;
            // Move the start pointer back to get the right most index
            start = mid + 1;
        }
        else if (key < v[mid])
            end = mid - 1;
        else
            start = mid + 1;
        mid = start + (end - start) / 2;
    }
    return ans;
}

std::pair<int, int> firstAndLastIndexSearch(std::vector<int> &v, int key)
{
    std::pair<int, int> p;
    p.first = firstOccurance(v, key);
    p.second = lastOccurance(v, key);
    return p;
}

int main()
{
    std::vector<int> v = {1, 3, 7, 7, 7, 7, 7, 9, 11, 23, 74};
    std::pair<int, int> p = firstAndLastIndexSearch(v, 7);
    std::cout << p.first << "," << p.second << std::endl;
}