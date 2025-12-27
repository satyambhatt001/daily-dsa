// Function to detect if a linked list contains a cycle
// Uses Floyd's Cycle Detection Algorithm (also called "Tortoise and Hare")
bool hasCycle(Node* head) {
    // Step 1: Edge case check
    // If the list is empty (head == NULL) OR has only one node (head->next == NULL)
    // then it cannot have a cycle. So we immediately return false.
    if (head == NULL || head->next == NULL)
        return false;

    // Step 2: Initialize two pointers for traversal
    // 'slow' pointer will move one step at a time
    Node* slow = head;
    // 'fast' pointer will move two steps at a time
    Node* fast = head;

    // Step 3: Traverse the linked list
    // The loop continues as long as 'fast' and 'fast->next' exist
    // This ensures we don't dereference NULL (avoid crash)
    while (fast && fast->next) {
        // Move 'slow' pointer by one node
        slow = slow->next;
        // Move 'fast' pointer by two nodes
        fast = fast->next->next;

        // Step 4: Check for cycle
        // If 'slow' and 'fast' point to the same node, a cycle exists
        // This works because in a cycle, the fast pointer will eventually "lap" the slow pointer
        if (slow == fast) {
            return true;  // Cycle detected
        }

        // If slow != fast, we continue the loop
        // We do NOT return false here, because the cycle may exist further in the list
    }

    // Step 5: If we exit the loop, it means 'fast' reached the end of the list
    // i.e., there is no cycle
    return false;
}
