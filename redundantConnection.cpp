class Solution {
public:

    // This array will store the "parent" of each node.
    // parent[i] = representative (leader) of the set containing i
    vector<int> parent;



    // ---------------- FIND FUNCTION ----------------
    // This function finds the ultimate parent (root) of node x
    // It also performs PATH COMPRESSION:
    // → while coming back from recursion, we directly attach x to root
    // → makes future find operations very fast (almost O(1))

    int find(int x) {

        // BASE CASE:
        // If a node is parent of itself, it is the root of its set
        if (parent[x] == x)
            return x;

        // RECURSIVE CASE:
        // Find root of parent[x] and attach x directly to that root
        // This is path compression optimization
        return parent[x] = find(parent[x]);
    }



    // ---------------- UNION FUNCTION ----------------
    // Tries to connect two nodes x and y
    // Returns:
    //   true  → if union was successful (no cycle)
    //   false → if x and y already connected (cycle detected)

    bool unite(int x, int y) {

        // Find representatives (ultimate parents) of both nodes
        int px = find(x);
        int py = find(y);

        // If both have SAME parent → already in same component
        // Adding this edge would create a CYCLE
        if (px == py)
            return false;

        // Otherwise, connect them:
        // Make parent of py as px
        // (merge set of y into set of x)
        parent[py] = px;

        return true;
    }



    // ---------------- MAIN FUNCTION ----------------
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        // Number of nodes = number of edges (given in problem)
        int n = edges.size();

        // Resize parent array for nodes 1 to n
        parent.resize(n + 1);



        // ---------- INITIALIZATION ----------
        // Initially every node is its own parent
        // Each node is a separate component
        for (int i = 1; i <= n; i++)
            parent[i] = i;



        // ---------- PROCESS EACH EDGE ----------
        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            // Try to unite u and v
            // If unite returns false → this edge forms a cycle
            if (!unite(u, v)) {

                // This is the redundant edge asked in question
                return e;
            }
        }



        // Ideally we never reach here because problem guarantees
        // one redundant edge exists
        return {};
    }
};
