class DisjointSet{
    public:
        vector<int>size;
        vector<int>parent;
        int num_groups;
        int maxi = 0;
    public:
        DisjointSet(int n){
            size.resize(n,1);
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
        int size_node(int node){
            return size[find_par(node)];
        }
        void union_size(int u , int v){
            int up_u = find_par(u);
            int up_v = find_par(v);
            if(up_u == up_v)return ;
            num_groups--;
            if(size[up_u]<size[up_v]){
                parent[up_u]=up_v;
                
                size[up_v]+=size[up_u];
            }
            else {
                parent[up_v]=up_u;
                size[up_u]+=size[up_v];
                maxi = max(maxi , size[up_u]);
            }
        }
        int total_groups(){
            return num_groups;
        }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet dsu (n*n);
        vector<vector<bool>> visited(n,vector<bool> (n,false));

        vector<pair<int,int>>direction = {
            {0,1}, {0,-1} , {1,0} , {-1,0}
        };
        queue<pair<int,int>> q;
        // bfs with disjoint set
        for(int i = 0;i<n;i++){
            for(int  j = 0;j<n;j++){
                if(visited[i][j]==true)continue;
                if(grid[i][j]==0)continue;
                int par_ind = i*n+j;
                q.push({i,j});
                while(!q.empty()){
                    auto  [k,m] = q.front();
                    q.pop();
                    if(visited[k][m]==true)continue;
                    visited[k][m]=true;
                    for(auto &[di,dj]: direction){
                        int ni = di+k;
                        int nj = dj+m;
                        if(0<=ni && ni<n && 0<=nj && nj<n && grid[ni][nj]==1){
                            q.push({ni,nj});
                            int child_ind = ni*n+nj;
                            dsu.union_size(par_ind,child_ind);                            
                        }
                    }
                }
            }
        }
        int maxi = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){                    
                    int ones = 1;
                    unordered_set<int> visited={};
                    for(auto &[di,dj]:direction){
                        int ni = di+i;
                        int nj = dj+j;
                        if(0<=ni && ni<n && 0<=nj && nj<n && grid[ni][nj]==1){
                            int child_ind = ni*n+nj;                  
                            int parent_curr = dsu.find_par(child_ind);
                            if(visited.count(parent_curr)!=0)continue;
                            visited.insert(parent_curr);          
                            ones+= dsu.size_node(child_ind);
                        }                 
                    }
                    
                    maxi = max(maxi,ones);       
                }
            }
        }
        return max(maxi,dsu.maxi);

    }
};