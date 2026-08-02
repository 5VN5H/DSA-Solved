class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long sum = 0;
        long long ans = 0;

        int left = 0;

        unordered_map<long long,int> mp;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];
            mp[nums[i]]++;

            if(i - left + 1 > k) {

                sum -= nums[left];

                mp[nums[left]]--;

                if(mp[nums[left]] == 0)
                    mp.erase(nums[left]);

                left++;
            }

            if(i - left + 1 == k && mp.size() == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};