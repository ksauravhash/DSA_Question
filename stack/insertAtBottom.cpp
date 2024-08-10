#include <iostream>

#include <stack>

void insertAtBottom(std::stack<char> &st, char data) {
  int size = st.size();
  std::stack<char> st2;
  while(!st.empty()){
    st2.push(st.top());
    st.pop();
  }
  st.push(data);
  while(!st2.empty()) {
    st.push(st2.top());
    st2.pop();
  }
  
}

void insertAtBottomRecur(std::stack<char> &st, int data) {
  if(st.empty()) {
    st.push(data);
    return;
  }

  int num = st.top();
  st.pop();
  insertAtBottomRecur(st, data);

  st.push(num);
}

int main() {
  std::string s = "Hello";
  std::stack<char> st1;
  for(char c: s)
    st1.push(c);

  insertAtBottomRecur(st1, 'k');

  s = "";
  while(!st1.empty())
  {
    s.push_back(st1.top());
    st1.pop();
  }

  std::cout << s << std::endl;
  return 0;
}