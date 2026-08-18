class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> count(51, 0);

        for (int i = 0; i <= n - k; i++) {

            unordered_set<int> st;

            // Current window
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Count this number as appearing in this window
            for (int x : st) {
                count[x]++;
            }
        }

        int ans = -1;

        for (int x = 0; x <= 50; x++) {
            if (count[x] == 1) {
                ans = x;
            }
        }

        return ans;
    }
};