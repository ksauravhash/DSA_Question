#include <iostream>

#include <stack>

void removeMid(std::stack<char> &st) {
  int count = 0;
  int size = st.size();
  std::stack<char> st2;
  while(count < size/2){
    st2.push(st.top());
    st.pop();
    count++;
  }
  st.pop();
  while(!st2.empty()) {
    st.push(st2.top());
    st2.pop();
  }
  
}

void removeMidRecur(std::stack<char> &st, int count, const int size) {
  if(count  == size/2) {
    st.pop();
    return;
  }

  int num = st.top();
  st.pop();
  removeMidRecur(st, count+1, size);

  st.push(num);
}

int main() {
  std::string s = "Hello";
  std::string s2 = "abcd";
  std::stack<char> st1;
  std::stack<char> st2;
  for(char c: s)
    st1.push(c);
  for(char c: s2)
    st2.push(c);
  removeMid(st1);
  removeMid(st2);

  s = "";
  s2 = "";
  while(!st1.empty())
  {
    s.push_back(st1.top());
    st1.pop();
  }
  while(!st2.empty())
  {
    s2.push_back(st2.top());
    st2.pop();
  }

  std::cout << s << std::endl;
  std::cout << s2 << std::endl;
  return 0;
}