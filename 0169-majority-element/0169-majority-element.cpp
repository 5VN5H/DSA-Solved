class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = 0;
        int cnt = 0;
        for(auto &x :nums){
            if(cnt == 0){
                cand = x;
                cnt =1;
            }
            else if (cand ==x){
                cnt++;
            }else{
                cnt--;
            }
        }
    return cand;
    }
};