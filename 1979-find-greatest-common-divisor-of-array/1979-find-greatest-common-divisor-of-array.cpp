class Solution {
public:
    int gcd(int mn, int mx) {
        while (mx!=0) {
            int temp = mx;
            mx = mn % mx;
            mn = temp;
        }
        return mn;
    }
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        return gcd(mn, mx);
    }
};