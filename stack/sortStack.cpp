#include <iostream>
#include <stack>
#include <vector>

void sortedInsert(std::stack<int> &st, int c)
{
  if (st.empty() || c > st.top())
  {
    st.push(c);
    return;
  }

  int top = st.top();
  st.pop();
  sortedInsert(st, c);
  st.push(top);
}

void sort(std::stack<int> &st)
{
  if (st.empty())
    return;
  int top = st.top();
  st.pop();
  sort(st);
  sortedInsert(st, top);
}

int main()
{
  std::vector<int> s = {-2, 5, -3, 7, 4};
  std::stack<int> st1;
  for (int c : s)
    st1.push(c);

  s.clear();

  sort(st1);

  while (!st1.empty())
  {
    s.push_back(st1.top());
    st1.pop();
  }

  for (int i : s)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}