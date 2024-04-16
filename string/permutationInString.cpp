/*
* Leetcode 567
* https://leetcode.com/problems/permutation-in-string/
*/
class Solution {

    bool checkMatch(int a[26], int b[26]) {
        for(int i = 0;i<26;i++) {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        int count[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
        }
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            int count2[26] = {0};
            for (int j = 0; j < s1.length(); j++) {
                count2[s2[i+j] - 'a']++;
            }
            if(checkMatch(count2, count))
                return true;
        }
        return false;
    }
};