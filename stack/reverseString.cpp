#include <iostream>

#include <stack>

std::string reverse(std::string str) {
  std::string ans;
  std::stack<char> stack;
  for(char c: str) {
    stack.push(c);
  }
  while(!stack.empty()) {
    ans += stack.top();
    stack.pop();
  }
  return ans;
  
}

int main() {
  std::string s = "Hello";
  std::string rev = reverse(s);
  std::cout << rev << std::endl;
  return 0;
}