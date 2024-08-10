#include <iostream>

#include <stack>


char match(char c) {
  switch (c)
  {
  case '}':
    return '{';
  case ']':
    return '[';
  case ')':
    return '(';
  
  }
  return '\0';
}

bool isValidParenthesis(std::string str)
{
  std::stack<char> stack;
  for (char c : str)
  {
    if (c == '(' || c == '{' || c == '[')
      stack.push(c);
    if (!stack.empty() &&(c == ')' || c == ']' || c == '}'))
    {
      if(stack.top() == match(c)) {
        stack.pop();
      }else
        return false;
    }
  }
  return stack.empty();
}

int main()
{
  std::string s = "[{}()]";
  std::string s2 = "[({)}]";
  std::cout << isValidParenthesis(s) << std::endl;
  std::cout << isValidParenthesis(s2) << std::endl;
  return 0;
}