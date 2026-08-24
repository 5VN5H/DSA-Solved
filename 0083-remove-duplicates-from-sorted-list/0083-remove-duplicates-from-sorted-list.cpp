class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* temp = head;
        ListNode* ans = head;

        unordered_set<int> visited;

        while (temp != nullptr) {
            if (visited.count(temp->val)) {
                ans->next = temp->next;
            } else {
                visited.insert(temp->val);
                ans = temp;
            }

            temp = temp->next;
        }

        return head;
    }
};