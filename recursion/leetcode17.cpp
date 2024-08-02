/*
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 */

class Solution {

    void solve(vector<string>&ans, const string st[], string output, int index, string digits) {
        if(output.length() == digits.size()) {
            if(output.length() > 0)
                ans.push_back(output);
            return;
        }  
        int digit = digits[index] - '0';
        for(int i = 0;i<st[digit].length();i++) {
            solve(ans, st, output+st[digit][i], index+1, digits);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string st[]= {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        vector<string> ans;
        string output;
        solve(ans, st, output, 0, digits);
        return ans;
    }
};