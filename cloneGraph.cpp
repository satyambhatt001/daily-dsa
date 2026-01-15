class Solution {
public:
    // This map stores the mapping:
    // original node  ->  its cloned node
    // Why needed?
    // 1. To avoid cloning the same node multiple times
    // 2. To handle cycles in the graph
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {

        // ---------- BASE CASE ----------
        // If the input node is NULL, there is no graph to clone
        // So simply return NULL
        if (node == NULL)
            return NULL;

        // ---------- ALREADY CLONED CHECK ----------
        // If this node has already been cloned earlier,
        // it will be present in the map
        // We return the cloned node directly
        // This prevents:
        // - infinite recursion (due to cycles)
        // - duplicate node creation
        if (mp.find(node) != mp.end())
            return mp[node];

        // ---------- CREATE CLONE ----------
        // Create a new node with the same value as the original node
        // Neighbors will be filled later
        Node* clone = new Node(node->val);

        // ---------- STORE MAPPING ----------
        // Store the mapping from original node to cloned node
        // IMPORTANT:
        // This must be done BEFORE cloning neighbors
        // so cycles can be handled safely
        mp[node] = clone;

        // ---------- CLONE NEIGHBORS ----------
        // Iterate through all neighbors of the original node
        for (Node* neigh : node->neighbors) {

            // Recursively clone each neighbor
            // cloneGraph(neigh) returns the cloned neighbor node

            // Add the cloned neighbor to the clone's neighbor list
            clone->neighbors.push_back(cloneGraph(neigh));
        }

        // ---------- RETURN RESULT ----------
        // Return the cloned version of the current node
        return clone;
    }
};
