class Solution {
public:
    int minrow(vector<vector<int>>& mat, int mid) {
        int max = INT_MIN;
        int ans = 0;
            for (int i = 1; i < mat.size(); i++) {
            if (mat[i][mid] > mat[ans][mid]) {
                ans =i;
            }
        }
        return ans;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = minrow(mat, mid);
            int left = (mid > 0) ? mat[row][mid - 1] : -1;
            int right = (mid < m - 1) ? mat[row][mid + 1] : -1;
            if(left<mat[row][mid] && right<mat[row][mid]){
                return {row,mid};
            }
            else if(left>mat[row][mid]){
                high = mid-1;
            }
            else{
                low =mid+1;
            }

        }
        return {-1,-1};
    }
};