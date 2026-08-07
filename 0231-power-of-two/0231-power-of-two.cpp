class Solution {
public:
    bool solve(long long x, int n) {
        if (x == n)
            return true;

        if (x > n)
            return false;

        return solve(x * 2, n);
    }

    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        return solve(1, n);
    }
};