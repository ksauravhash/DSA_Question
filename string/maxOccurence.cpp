#include <iostream>

char getMaxOccuringChar(std::string str) {
  char arr[26] = {0};
  for(int i = 0;i<str.length();i++) {
    char c = str[i];
    if(c >= 'a' && c <= 'z')
      arr[c - 'a']++;
    else if(c >= 'A' && c <= 'Z')
      arr[c-'A']++;
    else
      continue;
  }
  int max = 0;
  for(int i=0;i<26;i++) {
    if(arr[i] > arr[max])
      max = i;
  }
  return max + 'a';
}

int main() {
  std::string s;
  std::cin >> s;
  std::cout << getMaxOccuringChar(s) << std::endl;
}