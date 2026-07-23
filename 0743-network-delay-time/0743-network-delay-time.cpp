class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj (n+1,vector<int>(n+1,1e9));

        vector<int> shortest (n+1,1e9);

        for(const auto t:times){
            adj[t[0]][t[1]] = t[2];
        }
        shortest[0]=0;
        shortest[k]=0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>>pq;

        pq.push({0,k});

        while(!pq.empty()){
            auto [time , u] = pq.top();
            pq.pop();
            
            if(time>shortest[u])continue;
            for(int v = 0;v<=n;v++){
                int next_time = adj[u][v];
                if(adj[u][v]==1e9)continue;
                if(time+next_time<shortest[v]){
                    shortest[v]=time+next_time;
                    pq.push({time+next_time,v});
                }
            }
        }


        int res = -1;
        for(auto val : shortest){
            if(val==1e9)return -1;
            if(res<val){
                res=val;
            }
        }
        return res;
    }
};