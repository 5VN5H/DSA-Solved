class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, vector<int>& curr,
               int index) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            

            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
                curr.push_back(candidates[i]);

                solve(candidates, target - candidates[i], curr, i+ 1);
                curr.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> curr;

        solve(candidates, target, curr, 0);

        return ans;
    }
};