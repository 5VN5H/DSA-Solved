class Solution {
public:

    void solve(int index,
               vector<int>& nums,
               vector<int>& path,
               vector<vector<int>>& ans)
    {
        if(index == nums.size())
        {
            ans.push_back(path);
            return;
        }

        path.push_back(nums[index]);
        solve(index + 1, nums, path, ans);

        path.pop_back();

        solve(index + 1, nums, path, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> path;

        solve(0, nums, path, ans);

        return ans;
    }
};