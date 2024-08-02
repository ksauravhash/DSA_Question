#include <iostream>
#include <string>

using namespace std;

class Solution {


    int romanLetterToInt(char &c) {
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
public:
    int romanToInt(string s) {
        int integer = 0;
        for(int i = 0;i<s.length();i++) {
            char c = s[i];
            if(i == s.length() - 1)
                integer +=  romanLetterToInt(c);
            char n = s[i+1];
            int lValue = romanLetterToInt(c);
            int rValue = romanLetterToInt(n);
            if(rValue > lValue) {
                integer += rValue - lValue;
                i++;
            }else
                integer += lValue;
            
            
        }
        return integer;
    }
};

int main() {
  string s = "III";
  
  Solution sol;
  cout << sol.romanToInt(s) << endl;
  
}