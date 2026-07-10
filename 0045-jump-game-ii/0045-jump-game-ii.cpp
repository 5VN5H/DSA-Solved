class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpneed= 0;
        int currentend= 0;
        int farthestreach =0;
        for(int i =0 ;i<nums.size()-1;i++){
            farthestreach= max(farthestreach,i+nums[i]);
            if(i==currentend){
                jumpneed++;
                currentend=farthestreach;
            }
        }
        return jumpneed;
    }
};