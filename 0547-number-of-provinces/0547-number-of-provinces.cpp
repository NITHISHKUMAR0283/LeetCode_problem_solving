class Solution {
public:
    void explore(queue<int>& q ,unordered_set<int>& visited , vector<vector<int>> & isConnected){
        
        int n = isConnected.size();
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(int i = 0;i<n;i++){
                if(isConnected[current][i]==1){
                    if(visited.find(i)!=visited.end())continue;
                    visited.insert(i);
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> visited;

        queue<int> q ;
        int n = isConnected.size();
        int no_prov = 0;
        for(int i = 0;i<n;i++){
            if(visited.find(i)!=visited.end())continue;
            visited.insert(i);
            q.push(i);
            no_prov++;
            explore(q,visited,isConnected);

                        }
        return no_prov;
        
    }
};