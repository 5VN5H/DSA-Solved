class Solution {
public:

    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> ans;

    void solve(string &digits, int index, string current) {

        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {

            current.push_back(ch);

            solve(digits, index + 1, current);

            current.pop_back();

        } 
        
    }

    vector<string> letterCombinations(string digits) {

        solve(digits, 0, "");

        return ans;
    }
};