class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans  = INT_MIN;

        int n = nums.size();
        int sum = 0;
        double avg = 0;
        for(int i =0;i<k;i++){
            sum +=nums[i];
        }

        ans = (double)sum / k;
        for(int i = k;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-k];

            avg = (double)sum/k;

            ans = (double)max(ans,avg);
            
        }
        return ans;
    }
};