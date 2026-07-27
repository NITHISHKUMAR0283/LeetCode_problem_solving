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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet dsu(n);
        
        unordered_map<int,int> row(n);
        unordered_map<int,int> col(n);

        for(int i = 0;i<n;i++){
            int r = stones[i][0];
            int c = stones[i][1];
            if(row.count(r)){
                dsu.union_rank(i,row[r]);
            }
            else{
                row[r]=i;
            }
            if(col.count(c)){
                dsu.union_rank(i,col[c]);
            }
            else{
                col[c]=i;
            }
        }
        return n-dsu.total_groups();
    }
};