#include <iostream>

void merge(int *arr, int s, int e)
{
  int mid = s + (e - s) / 2;

  int s1 = s;
  int s2 = mid + 1;
  int e1 = mid;
  int e2 = e;

  int arr1[s2 - s1 + 1];
  int arr2[e2 - e1 + 1];

  for(int i = s1;i<=mid;i++) {
    arr1[i-s1] = arr[i-s1];
  }
  for(int i = s2;i<=mid;i++) {
    arr2[i-s2] = arr[i-s2];
  }

  int i = 0, j = s2;
  int k = 0;
  while (i <= e1 && j <= e2)
  {
    if (arr[i] < arr[j])
    {
      arr[k++] = arr1[i++];
    }else {
      arr[k++] = arr2[j++ - s2];
    }
  }
  while(i <= s1) {
    arr[k++] = arr1[i++];
  }
  while(j <= s2) {
    arr[k++] = arr2[j++ - s2];
  }
}

void mergeSort(int *arr, int s, int e)
{
  if (s >= e)
    return;

  int mid = s + (e - s) / 2;

  // Merge Sort on the left
  mergeSort(arr, s, mid);

  // Merge Sort on the right
  mergeSort(arr, mid = 1, e);

  // Merge the arrays
  merge(arr, s, e);
}

int main() {
  int arr[] = {5,4,2,1};
  int e = sizeof(arr)/sizeof(int)-1;
  mergeSort(arr, 0, e);
  for(int i = 0;i<=e;i++) {
    std::cout << arr[i] << '\t';
  }
  std::cout << std::endl;

  return 0;
}