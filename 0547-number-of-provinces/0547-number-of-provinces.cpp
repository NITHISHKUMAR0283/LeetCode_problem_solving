class Solution {
public:
    void explore(queue<int>& q ,vector<bool> & visited , vector<vector<int>> & isConnected){
        
        int n = isConnected.size();
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(int i = 0;i<n;i++){
                if(isConnected[current][i]==1){
                    if(visited[i])continue;
                    visited[i]=true;;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<bool> visited(n,false);

        queue<int> q ;
        int no_prov = 0;
        for(int i = 0;i<n;i++){
            if(visited[i])continue;
            visited[i];
            q.push(i);
            no_prov++;
            explore(q,visited,isConnected);

                        }
        return no_prov;
        
    }
};