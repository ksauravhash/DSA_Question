#include <iostream>
#include <vector>

int partition(std::vector<int> &v, int s, int e)
{
  int pivot = v[s];
  int count = 0;
  for (int i = s; i <= e; i++)
  {
    if (v[i] < pivot)
      count++;
  }
  int pivotIndex = s + count;

  std::swap(v[pivotIndex], v[s]);
  int i = s;
  int j = e;
  while (i < pivotIndex && j > pivotIndex)
  {
    while (v[i] < pivotIndex)
      i++;
    while (v[j] > pivotIndex)
      j--;
    if(i < pivotIndex &&  j > pivotIndex)
      std::swap(v[i++], v[j--]);
  }
  return pivotIndex;
}

void quickSort(std::vector<int> &v, int s, int e)
{
  if (s >= e)
    return;

  int partIndex = partition(v, s, e);
  quickSort(v, s, partIndex - 1);
  quickSort(v, partIndex + 1, e);
}

int main()
{
  std::vector<int> nums = {7, 1, 4, 5, 3, 0};
  quickSort(nums, 0, nums.size() - 1);

  for (auto i : nums)
  {
    std::cout << i << '\t';
  }
  std::cout << std::endl;
  ;
}