ListNode* removeNthNode(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* temp = dummy;

    for (int i = 0; i < n - 1; i++) {
        temp = temp->next;
    }

    temp->next = temp->next->next;

    return dummy->next;
}
