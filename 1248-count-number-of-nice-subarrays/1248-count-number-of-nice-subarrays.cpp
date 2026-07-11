class Solution {
public:
    int atmostk(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }
        int left =0;
        int count = 0;
        int ans =0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]%2!=0){
                count++;
            }
            while(count>k){
                if(nums[left]%2!=0){
                    count--;
                }
                left++;
            }
            ans+=right-left+1;
        }
        return ans;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums,k)-atmostk(nums,k-1);
    }
};