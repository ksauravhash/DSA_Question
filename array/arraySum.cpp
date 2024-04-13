#include <iostream>
#include <vector>

void reverse(std::vector<int>& v) {
  int b = 0;
  int e = v.size()-1;
  while(b < e) {
    std::swap(v[b++], v[e--]);
  }
}

int main() {
  std::vector<int> v = {1,2,3};
  std::vector<int> v2 = {9,1,2};
  std::vector<int> v3;
  int i = v.size()-1;
  int j = v2.size()-1;
  int carry = 0;
  int digit, sum;
  while(i>=0 && j>=0) {
    sum = v[i] + v2[j] + carry;
    digit = sum%10;
    carry = sum/10;
    v3.push_back(digit);
    i--;
    j--;
  }

  // Case 1 when first has more digits
  while(i >= 0) {
    sum = v[i] + carry;
    digit = sum%10;
    carry = sum/10;
    v3.push_back(digit);
    i--;
  }
  
  // Case 2 when 2nd has more digits
  while(j>= 0) {
    sum = v2[i] + carry;
    digit = sum%10;
    carry = sum/10;
    v3.push_back(digit);
    j--;
  }

  // Case 3 when carry is left at the end
  if(carry !=0) {
    v3.push_back(carry);
  }

  reverse(v3);

  for(int i: v3) {
    std::cout << i << '\t';
  }
  std::cout << std::endl;
}