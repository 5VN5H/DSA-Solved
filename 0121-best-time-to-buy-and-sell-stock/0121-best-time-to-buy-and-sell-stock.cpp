class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX;
        int maxp = 0;

        for(int i =0;i<prices.size();i++){
            maxp = max(maxp, prices[i]-minp);
            minp = min(minp,prices[i]);
        }
        return maxp;
    }
};