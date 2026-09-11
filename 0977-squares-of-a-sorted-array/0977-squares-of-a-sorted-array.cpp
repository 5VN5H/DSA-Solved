class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans.push_back((long long)nums[left] * nums[left]);
                left++;
            } else {
                ans.push_back((long long)nums[right] * nums[right]);
                right--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};