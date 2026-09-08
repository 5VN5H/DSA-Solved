class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (int gift : gifts) {
            pq.push(gift);
        }

        while (k--) {
            int largest = pq.top();
            pq.pop();

            int remaining = sqrt(largest);

            pq.push(remaining);
        }

        long long ans = 0;

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};