class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<int>> effs (r,vector<int>(c,1e9));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        
        vector<pair<int,int>> direction = {
            {0,1} , {0,-1} , {1,0} , {-1,0}
        } ;
        int min_eff = 1e9;
        while(!pq.empty()){
            auto [eff , p ] = pq.top();
            pq.pop();
            auto [i,j] = p;
            if(eff>effs[i][j])continue;
            if(i==r-1 && j==c-1){
                min_eff = min(min_eff,eff);
            }
            for(auto [m,k]: direction){
                int ni = i+m;
                int nj = j+k;
                if(0<=ni && ni<r && 0<=nj && nj<c){
                    int nh = heights[ni][nj];
                    int next_eff = max(eff,abs(heights[i][j]-heights[ni][nj]));
                    if(effs[ni][nj]>next_eff){
                        effs[ni][nj]=next_eff;
                        pq.push({next_eff,{ni,nj}});
                    }
                }
            }
         }
         return min_eff;

    }
};