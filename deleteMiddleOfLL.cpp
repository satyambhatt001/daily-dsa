class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = curr;
            curr = curr->next;
            fast = fast->next->next;
        }

        ListNode* next = curr->next;
        prev->next = next;

        delete curr;

        return head;
    }
};
