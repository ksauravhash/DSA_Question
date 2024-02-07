#include <iostream>
#include <vector>

int binarySearch(std::vector<int> &v, int key)
{
    int start = 0;
    int end = v.size() - 1;
    // Optised to handle large numbers
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (v[mid] == key)
            return mid;
        else if (key < v[mid])
            end = mid - 1;
        else
            start = mid + 1;
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    std::vector<int> v = {1, 3, 7, 9, 11, 23, 74};

    if (binarySearch(v, 7) != -1)
        std::cout << "Present" << std::endl;
    else
        std::cout << "Not Present" << std::endl;
}