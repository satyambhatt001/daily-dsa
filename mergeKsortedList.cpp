// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6


//bf solution
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a vector to store all the values from the linked lists
        vector<int> v;
        for (ListNode* list : lists) {
            while (list != nullptr) {
                v.push_back(list->val); // Add the value of the current node to the vector
                list = list->next;      // Move to the next node in the linked list
            }
        }
        sort(v.begin(), v.end()); // Sort the values
        // Create a new linked list from the sorted values
        ListNode* dummy = new ListNode(0);
        ListNode* merge = dummy;
        for (int val : v) {
            merge->next = new ListNode(val);
            merge = merge->next;
        }
        return dummy.next;
    }
};

//Optimal solution using priority queue with time complexity O(N log k) where N is the 
//total number of nodes and k is the number of linked lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
}; */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        ListNode dummy;
        ListNode* merge = &dummy;

        while (!pq.empty()) {

            ListNode* node = pq.top();
            pq.pop();

            merge->next = node;
            merge = merge->next;

            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};
