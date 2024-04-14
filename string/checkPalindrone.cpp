#include <iostream>
#include <vector>

char toLower(char ch)
{
  if (ch >= 'a' && ch <= 'z')
    return ch;
  else
    return ch - 'A' + 'a';
}

char isNumberOrLetter(char ch)
{
  return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

bool checkPalindrome(std::vector<char> v)
{
  int s = 0;
  int e = v.size() - 1;

  while (s < e)
  {
    if (!isNumberOrLetter(v[s]) || !isNumberOrLetter(v[e]))
    {
      s++;
      e--;
    }
      if (toLower(v[s++]) != toLower(v[e--]))
        return false;
  }
  return true;
}

int main()
{
  std::vector<char> v = {'A', '2', '1', 'b', 'a'};
  if (checkPalindrome(v))
    std::cout << "Palindrome" << std::endl;
  else
    std::cout << "Not Palindrome" << std::endl;
  return 0;
}