class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // ---------------------------------------------------
        // STEP 1: Create Adjacency List and Indegree Array
        // ---------------------------------------------------

        // adj[i] will store list of courses that depend on course i
        vector<vector<int>> adj(numCourses);

        // indegree[i] = how many prerequisites course i has
        vector<int> indegree(numCourses, 0);

        // ---------------------------------------------------
        // STEP 2: Build Graph from prerequisites
        // ---------------------------------------------------

        // Each prerequisite pair is like [a, b]
        // Meaning: to do course a → you must finish course b first
        // So we create a directed edge:  b → a
        for(auto &p : prerequisites) {

            int a = p[0];   // course we want to take
            int b = p[1];   // prerequisite course

            // Add edge b → a
            adj[b].push_back(a);

            // Increase indegree of a
            indegree[a]++;
        }

        // ---------------------------------------------------
        // STEP 3: Put all courses with indegree 0 in queue
        // ---------------------------------------------------

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {

            // If a course has NO prerequisite
            // we can take it immediately
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // This will count how many courses we are able to finish
        int count = 0;

        // ---------------------------------------------------
        // STEP 4: Start BFS (Kahn's Algorithm)
        // ---------------------------------------------------

        while(!q.empty()) {

            // Take one course that has no remaining prerequisite
            int current = q.front();
            q.pop();

            // We are able to complete this course
            count++;

            // Now check all courses that depend on 'current'
            for(int nextCourse : adj[current]) {

                // Since we completed 'current',
                // one prerequisite of nextCourse is removed
                indegree[nextCourse]--;

                // If nextCourse has no more prerequisites
                // it becomes ready to take
                if(indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // ---------------------------------------------------
        // STEP 5: Final Check
        // ---------------------------------------------------

        // If we were able to finish ALL courses → no cycle
        if(count == numCourses)
            return true;

        // Else some courses are stuck in cycle
        return false;
    }
};
