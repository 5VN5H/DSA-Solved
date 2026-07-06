class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char a = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != a) {
                    return ans;
                }
            }
            ans += a;
        }
        return ans;
    }
};