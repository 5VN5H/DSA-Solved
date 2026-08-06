class Solution {
public:
    int prodig(int n) {
        int ans = 1;

        while (n > 0) {
            int digit = n % 10;
            ans *= digit;
            n /= 10;
        }

        return ans;
    }

    int smallestNumber(int n, int t) {
        for (int i = n; ; i++) {
            if (prodig(i) % t == 0) {
                return i;
            }
        }
    }
};