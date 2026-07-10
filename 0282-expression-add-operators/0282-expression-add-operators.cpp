class Solution {
public:
    vector<string> ans;
    void solve(string& num, int& target, int index, long long value, string path,
               long long prev) {
        if (index == num.size()) {
            if (value == target) {
                ans.push_back(path);
            }
            return;
        }
        long long curr = 0;
        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0')
                break;

            curr = curr * 10 + (num[i] - '0');

            if (index == 0) {
                solve(num, target, i + 1, curr, to_string(curr), curr);
            } else {
                solve(num, target, i + 1, value+curr,
                      path + "+" + to_string(curr), curr);
                solve(num, target, i + 1, value-curr,
                      path + "-" + to_string(curr), -curr);
                solve(num, target, i + 1, value - prev + prev * curr,
                      path + "*" + to_string(curr), prev * curr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, 0, "", 0);
        return ans;
    }
};