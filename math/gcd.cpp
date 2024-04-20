#include <iostream>


// Euclid's Algorithm
int gcd(int a, int b) {
  while(a!=0 && b!=0) {
    if(a > b)
      a-=b;
    else
      b-=a;
  }
  if(a) {
    return a;
  }
  return b;
}

int main() {
  std::cout << gcd(36,48);
}