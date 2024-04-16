/*
* Leetcode 1910
* https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        auto pos = s.find(part);
        while(s.length() > 0 && pos < s.length()) {
            s.erase(pos, part.length());
            pos = s.find(part);
       }
        return s;
    }
};