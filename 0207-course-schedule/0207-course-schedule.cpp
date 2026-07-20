class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses,vector<int>(numCourses,0));        
        vector<int> indegree(numCourses,0);

        for(auto& pair:prerequisites){
                adj[pair[1]][pair[0]]=1;              
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
            for(int v =0; v<numCourses;v++){
                if(adj[node][v]!=1)continue;
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