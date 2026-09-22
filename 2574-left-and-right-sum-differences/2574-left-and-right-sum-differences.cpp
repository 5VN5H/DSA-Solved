class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = 0;

        // Calculate total sum
        for (int x : nums) {
            total += x;
        }

        vector<int> ans;
        int leftSum = 0;

        for (int x : nums) {
            // Remove current element first
            total -= x;

            // total is now rightSum
            int rightSum = total;

            ans.push_back(abs(leftSum - rightSum));

            // Add current element to left side
            leftSum += x;
        }

        return ans;
    }
};
