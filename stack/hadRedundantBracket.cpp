#include <stack>
#include <iostream>

bool isOp(char c) {
  switch(c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      return true;
  } 
  return false;
}

/**
 * Push each opening bracket or operator into the stack
 * If on closing bracket check if an an operator is present in the stack
 *  Until the opening is found pop and pop the opening bracket too.
 * If the stack is not empty then it is redundant.
 */
bool hasRedundantBracket(std::string expression)
{
  std::stack<char> st;
  for(char c: expression) {
    if(c == '(' || isOp(c))
      st.push(c);
    else {
      if(c == ')' && isOp(st.top())) {
        while(st.top() != '(')
          st.pop();
        st.pop();
      } 
    }
  }
  return !st.empty();
}

int main()
{
  std::string s = "((a+c)+d)";
  std::string s1 = "(a)";
  std::cout << hasRedundantBracket(s) << std::endl;
  std::cout << hasRedundantBracket(s1) << std::endl;
}