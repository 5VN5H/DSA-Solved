class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        // Need at least 3 nodes to have a critical point
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next != nullptr) {

            ListNode* next = curr->next;

            // Check if curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {

                // First critical point
                if (first == -1) {
                    first = pos;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - last);
                }

                // Current becomes the latest critical point
                last = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        // Fewer than 2 critical points
        if (first == -1 || first == last)
            return ans;

        int maxDist = last - first;

        ans[0] = minDist;
        ans[1] = maxDist;

        return ans;
    }
};