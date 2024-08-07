#include <iostream>

int binarySearch(int arr[], int s, int e, int key)
{
  if (s > e)
    return false;

  int mid = s + (e - s) / 2;

  if (arr[mid] == key)
    return true;
  else if (arr[mid] < key)
    return binarySearch(arr, mid + 1, e, key);
  else
    return binarySearch(arr, s, mid - 1, key);
}

int main()
{
  int arr[] = {1, 2, 5, 7, 13, 33};
  std::cout << binarySearch(arr, 0, 6, 33) << std::endl;
}