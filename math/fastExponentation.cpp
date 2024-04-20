#include <iostream>

int pow(int a, int b)
{
  int res = 1;
  while(b > 0) {
    // Odd
    if(b & 1) {
      res *= a;
    }
    a = a * a;
    // Divide by 2;
    b = b >> 1;

  }
  return res;
}

int main()
{
  std::cout << pow(5, 2) << std::endl;
  return 0;
}