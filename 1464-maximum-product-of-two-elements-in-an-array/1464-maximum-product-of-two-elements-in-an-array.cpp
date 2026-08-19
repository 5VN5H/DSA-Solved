class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        for(auto x : nums){
            pq.push(x);
        }
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        return(x-1)*(y-1);
    }
};