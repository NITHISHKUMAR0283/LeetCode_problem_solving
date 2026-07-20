class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,vector<int>> adj;        
        vector<int> indegree(numCourses);

        for(auto& pair:prerequisites){
                adj[pair[1]].push_back(pair[0]);                
                indegree[pair[0]]++;
            }
        


        queue <int> q;

        for(int u = 0;u<numCourses;u++){
            if(indegree[u]==0){
                q.push(u);
            }
        }


        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto v :adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        for(auto degree:indegree){
            if(degree!=0)return false;
        }
        return true;
    }
};