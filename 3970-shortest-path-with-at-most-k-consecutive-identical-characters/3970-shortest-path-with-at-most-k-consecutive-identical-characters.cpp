class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> nei(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            nei[u].push_back({v,w});
        }
        vector<vector<int>> dist (n,vector<int>(k+1,1e9));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> min_heap;

        dist[0][1]=0;
        min_heap.push({0,0,1});

        while(!min_heap.empty()){
            auto curr = min_heap.top();
            min_heap.pop();

            int d = curr[0];
            int u = curr[1];
            int count = curr[2];
            if(d>dist[u][count])continue;
            if(u==n-1)return d;
            for(auto[v,w]:nei[u]){
                int next_counter = (labels[u]==labels[v])?count+1:1;
                if(next_counter<=k){
                if(w+d<dist[v][next_counter]){
                    dist[v][next_counter]=w+d;
                    min_heap.push({w+d,v,next_counter});
                }
            }}
        }
        return -1;

    }
};