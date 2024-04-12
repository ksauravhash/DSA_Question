#include <vector>
#include <iostream>

int main() {


  std::vector<int> arr = {2, 4, 6, 8, 10};
  std::vector<int> arr2 = {3, 5, 7, 9,};
  std::vector<int> arr3;

  int i = 0;
  int j = 0;
  
  while(i < arr.size() && j < arr2.size() )
  {
    if(arr[i] < arr2[j])
      arr3.push_back(arr[i++]);
    else
      arr3.push_back(arr2[j++]);
  }
  while(i < arr.size())
    arr3.push_back(arr[i++]);
  while(j < arr2.size())
    arr3.push_back(arr2[j++]);

  for(int i: arr3)
    std::cout << i << std::endl;

  return 0;
}