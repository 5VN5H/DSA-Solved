class Solution {
public:

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void solve(string s, vector<string>& current,
               vector<vector<string>>& ans) {
        if (s.length() == 0) {
            ans.push_back(current);
            return;
        }

        for (int len = 1; len <= s.length(); len++) {

            string part = s.substr(0, len);

            if (isPalindrome(part)) {

                current.push_back(part);

                string remaining = s.substr(len);

                solve(remaining, current, ans);

                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> current;

        solve(s, current, ans);

        return ans;
    }
};