class Solution {
public: 
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int index,vector<int>&curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(index == candidates.size()){
            return ;
        }

        if(target>=candidates[index]){

            curr.push_back(candidates[index]);

            solve(candidates,
                  target-candidates[index],
                  index,
                  curr);

            curr.pop_back();
        }

        solve(candidates,
                  target,
                  index+1,
                  curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;

        solve(candidates,target,0,curr);

        return ans;
    }
};