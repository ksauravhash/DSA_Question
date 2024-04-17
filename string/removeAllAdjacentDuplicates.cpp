/*
* Leetcode 1047
* https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string
*/

class Solution {
public:
    string removeDuplicates(string s) {
        string newStr  = s;
        bool change = true;
        while(change) {
            change = false;
            string temp = "";
            for(int i = 0;i<newStr.length();i++) {
                if(i < newStr.length() && newStr[i] == newStr[i+1]) {
                    change = true;
                    i++;
                    continue;
                }
                temp.push_back(newStr[i]);
            }
            newStr = temp;
        }
        return newStr;
    }
};