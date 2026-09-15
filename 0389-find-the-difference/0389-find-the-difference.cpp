class Solution {
public:
    char findTheDifference(string s, string t) {

        unordered_map<char, int> mp;

        for (char x : s) {
            mp[x]++;
        }

        for (char x : t) {
            if (mp[x] == 0) {
                return x;
            }
            mp[x]--;
        }

        return '0';
    }
};