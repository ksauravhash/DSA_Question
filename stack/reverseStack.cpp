#include <iostream>
#include <stack>

void insertAtBottom(std::stack<char> &st, int data) {
  if(st.empty()) {
    st.push(data);
    return;
  }

  int num = st.top();
  st.pop();
  insertAtBottom(st, data);

  st.push(num);
}


void reverseStack(std::stack<char> &st) {
  if(st.empty())
    return;
  int num = st.top();
  st.pop();
  reverseStack(st);
  insertAtBottom(st, num);
}


int main() {
  std::string s = "Hello";
  std::stack<char> st1;
  for(char c: s)
    st1.push(c);

  reverseStack(st1);

  s = "";
  while(!st1.empty())
  {
    s.push_back(st1.top());
    st1.pop();
  }

  std::cout << s << std::endl;
  return 0;
}