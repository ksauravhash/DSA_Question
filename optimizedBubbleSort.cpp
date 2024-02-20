#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        bool swapped = false;
        for (int j = 0; j < v.size() - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
                // Change it to true if it is being swapped
                swapped = true;
            }
        }
        // If it is already sorted
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    std::vector<int> values = {10, 2, 1, 7, 6, 9};
    bubbleSort(values);
    for (auto item : values)
    {
        std::cout << item << std::endl;
    }
    return 0;
}