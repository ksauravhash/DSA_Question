#include <vector>
#include <iostream>
#include <algorithm>

int main() {
  std::vector<int> v = {1,2,3,4,5,6,7};

  int b =0, e = v.size()-1;

  while(b<e) {
    std::swap(v[b], v[e]);
    b++;
    e--;
  }

  for(int i: v) {
    std:: cout << i << std::endl; 
  }

  return 0;
}