class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(auto it : graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        vector<int> safe;
        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(int nei : adj[node]) {
                indegree[nei]--;

                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};