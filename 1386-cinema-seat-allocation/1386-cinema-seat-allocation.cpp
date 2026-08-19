class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        map<int, set<int>> rows;

        // Store reserved seats row-wise
        for (auto &seat : reservedSeats) {
            rows[seat[0]].insert(seat[1]);
        }

        int ans = 0;

        // Rows with no reservations
        ans += (n - rows.size()) * 2;

        // Process rows having reservations
        for (auto &[row, seats] : rows) {

            bool left = true;   // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for (int s : seats) {

                if (s >= 2 && s <= 5)
                    left = false;

                if (s >= 4 && s <= 7)
                    middle = false;

                if (s >= 6 && s <= 9)
                    right = false;
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};