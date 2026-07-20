class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);        
        vector<int> indegree(numCourses,0);

        for(auto& pair:prerequisites){
                adj[pair[1]].push_back(pair[0]);;              
                indegree[pair[0]]++;
            }
        
        queue <int> q;
        int count = 0;
        for(int u = 0;u<numCourses;u++){
            if(indegree[u]==0){
                q.push(u);
            }
        }


        while(!q.empty()){
            auto node = q.front();
            q.pop();
            count++;
            for(auto v : adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(count!=numCourses)return false;
        return true;
    }
};