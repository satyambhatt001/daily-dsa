// Function to check if the contents of an array form a palindrome
bool checkPalindrome(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array
    int s = 0;          // Start pointer
    int e = n - 1;      // End pointer

    // Traverse the array from both ends
    while (s <= e) {
        // If elements at the current pointers don't match, it's not a palindrome
        if (arr[s] != arr[e]) {
            return 0; // Return false (0) if mismatch found
        }
        s++; // Move start pointer forward
        e--; // Move end pointer backward
    }

    // If loop completes without mismatches, it's a palindrome
    return 1; // Return true (1)
}

// Node structure assumed to be defined elsewhere
// struct Node {
//     int data;
//     Node* next;
// };

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    Node* temp = head;        // Temporary pointer to traverse the linked list
    vector<int> arr;          // Vector to store the linked list elements

    // Traverse the linked list and store each element in the vector
    while (temp != NULL) {
        arr.push_back(temp->data); // Append current node's data to the array
        temp = temp->next;         // Move to the next node
    }

    // Use the helper function to check if the array is a palindrome
    return checkPalindrome(arr);
}

// 2nd approach

#include <stack>

bool isPalindrome(Node* head) {
    stack<int> st;
    Node* temp = head;

    while (temp) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp) {
        if (temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }

    return true;
}
