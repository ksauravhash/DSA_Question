#include <iostream>

void printWave(int arr[][4])
{
  for (int col = 0; col < 4; col++)
  {
    if (col & 1)
    {
      for (int row = 3; row >= 0; row--)
      {
        std::cout << arr[row][col] << '\t';
      }
    }
    else
    {
      for (int row = 0; row < 4; row++)
      {
        std::cout << arr[row][col] << '\t';
      }
    }
    std::cout << std::endl;
  }
}

int main()
{
  int arr[4][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}};
  printWave(arr);
  return 0;
}