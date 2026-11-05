class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n =nums.size();
        int cm = nums[0];
        int tm = nums[0];
        for(int i =1;i<n;i++){
            cm = max(nums[i],cm+nums[i]);
            tm = max(tm, cm);
        }
        int cmi = nums[0];
        int tmi = nums[0];
        for(int i =1;i<n;i++){
            cmi = min(nums[i],cmi+nums[i]);
            tmi = min(tmi, cmi);
        }

        return max(tm,abs(tmi));
    }
};