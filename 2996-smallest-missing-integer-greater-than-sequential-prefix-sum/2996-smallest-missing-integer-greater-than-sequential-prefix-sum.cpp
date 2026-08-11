//
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<int> prefix(nums.size());

        unordered_set<int> st;
        prefix[0]=nums[0];
        for(int i= 1 ;i<nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i];
        }

        int last = 0;
        for(int j =1;j<nums.size();j++){
            if(nums[j]==nums[j-1]+1){
                last = j;
            }else{
                break;
            }
        }

        for(int x :nums){
            st.insert(x);
        }

        int sum = prefix[last];

        while(st.count(sum)){
            sum++;
        }
        return sum;
    }
};