class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int t = n;

        while (t > 0) {
            int a = t % 10;
            sum += a;
            product *= a;

            t /= 10;
        }

        if (n % (sum+product) == 0) {
            return true;
        }

        return false;
    }
};