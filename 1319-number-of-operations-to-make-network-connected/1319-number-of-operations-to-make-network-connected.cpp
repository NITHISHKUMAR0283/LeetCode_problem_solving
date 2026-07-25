class DisjointSet{
    private:
        vector<int>rank;
        vector<int>parent;
        int num_groups;
    public:
        DisjointSet(int n){
            rank.resize(n,0);
            parent.resize(n);
            for(int i = 0;i<n;i++){
                parent[i]=i;
            }
            num_groups=n;
        }
        int find_par(int node){
            if(parent[node]==node)return node;
            return parent[node]=find_par(parent[node]);
        }
        void union_rank(int u , int v){
            int up_u = find_par(u);
            int up_v = find_par(v);
            if(up_u == up_v)return;
            num_groups--;
            if(rank[up_u]<rank[up_v]){
                parent[up_u]=up_v;
            }
            else if(rank[up_u]>rank[up_v]){
                parent[up_v]=up_u;
            }
            else{
                parent[up_v]=up_u;
                rank[up_u]++;
            }
        }
        int total_groups(){
            return num_groups;
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet dsu(n);
        
        for(const auto c:connections){
            dsu.union_rank(c[0],c[1]);
        }
        int edges = connections.size();
        int groups = dsu.total_groups();
        if(edges<n-1)return -1;
        return groups-1;
        
    }
};