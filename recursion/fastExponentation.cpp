#include <iostream>

int pow(int a, int b) {
  if(b==0)
    return 1;
  if(b==1)
    return a;
  int ans = pow(a,b/2);
  ans = ans * ans;
  if(b & 1) {
    return a * ans;
  }else {
    return ans;
  }
}


int main() {
  std::cout <<pow(2,4)<<std::endl;
  return 0;
}