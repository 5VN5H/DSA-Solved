class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int count = 0;
        int el = -1;
        int n = nums.size();

        for (auto i : nums) {
            if (count == 0) {
                el = i;
                count = 1;
            } else if (el == i) {
                count++;
            } else {
                count--;
            }
        }
        int totalcount = 0;
        for (auto i : nums) {
            if (i == el) {
                totalcount++;
            }
        }
        int leftcount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el) {
                leftcount++;
            }
            int rightcount = totalcount - leftcount;
            int ls = i + 1;
            int rs = nums.size() - i - 1;
            if (leftcount > ls / 2 && rightcount > rs / 2) {
                return i;
            }
        }

        return -1;
    }
};