/*
* Leetcode 125
* https://leetcode.com/problems/valid-palindrome
*/
class Solution {
    bool isValid(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9'));
    }

    char toLowerIfChar(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0') && ch <= '9')
            return ch;
        else
            return ch - 'A' + 'a';
    }

public:
    bool isPalindrome(string s) {
        std::string temp = "";

        for (int i = 0; i < s.length(); i++) {
            if (isValid(s[i]))
                temp.push_back(toLowerIfChar(s[i]));
        }

        int b = 0;
        int e = temp.size() - 1;
        while (b < e) {
            if (temp[b++] != temp[e--])
                return false;
        }
        return true;
    }
};