#include <iostream>
#include <vector>

void print(std::vector<int> v)
{
    for (auto item : v)
    {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sort01(std::vector<int> &v)
{
    int left = 0, right = v.size() - 1;
    while (left < right)
    {
        while (v[left] != 1 && left < right)
            left++;

        while (v[right] != 0 && left < right)
            right--;
        if (v[left] == 1 && v[right] == 0 && left < right)
        {
            swap(v[left], v[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    std::vector<int> v = {0, 1, 0, 1, 1, 1, 1, 0};
    sort01(v);
    print(v);
}