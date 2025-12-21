// Helper function to recursively find and remove the nth node from the end
int removeHelper(Node* &head, int n) {
    // Base case: if we reach the end of the list
    if (head == NULL)
        return 0;  // return 0 because we've reached beyond the last node

    // Recursive call: move to the next node
    // This keeps going until we reach NULL (the end of the list)
    int posFromEnd = removeHelper(head->next, n) + 1;

    // After recursion starts to return back (unwind),
    // we count how far from the end we are (1 means last node, 2 means second last, etc.)

    // When we find the node that is nth from the end
    if (posFromEnd == n) {
        // Save the current node in a temporary pointer
        Node* temp = head;

        // Move the head pointer ahead to skip the current node
        head = head->next;

        // Delete the unwanted node to free memory
        delete temp;
    }

    // Return the position from the end to previous calls
    return posFromEnd;
}

// Main function that calls the helper and returns the updated head
Node* removeNth(Node* head, int n) {
    removeHelper(head, n);  // perform the removal
    return head;            // return possibly updated head
}


