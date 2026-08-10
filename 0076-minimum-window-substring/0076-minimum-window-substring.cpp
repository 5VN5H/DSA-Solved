class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int required = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add s[right] to the window
            if (need[s[right]] > 0) {
                required--;
            }

            need[s[right]]--;

            // Window is valid
            while (required == 0) {

                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove s[left]
                need[s[left]]++;

                if (need[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};