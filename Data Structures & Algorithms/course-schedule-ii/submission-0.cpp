class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(const auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        vector<int> res;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int next : adj[node]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                    res.push_back(next);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};
