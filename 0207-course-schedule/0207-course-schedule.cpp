class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for(auto nei : adj[node]) {
                indegree[nei]--;

                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return count == numCourses;
    }
};