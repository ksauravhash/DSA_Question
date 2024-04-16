#include <iostream>

int main()
{
  std::string str = "";
  std::string inp;
  getline(std::cin, inp);
  for (int i = 0; i < inp.length(); i++)
  {
    if (inp[i] == ' ')
    {
      str.push_back('@');
      str.push_back('4');
      str.push_back('0');
    }
    else {
      str.push_back(inp[i]);
    }
  }
  std::cout << str << std::endl;
}