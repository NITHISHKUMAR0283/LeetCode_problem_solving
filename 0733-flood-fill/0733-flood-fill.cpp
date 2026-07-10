class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int start_color = image[sr][sc];
       int n = image.size();
       int m = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<bool>> visited (n,vector<bool>(m,false));
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            image[r][c]=color;
            visited[r][c]=true;
            for(auto [i , j ] : direction){
                int newrow = i+r;
                int newcol = j+c;
                if(newrow<0|| newrow>n-1 || newcol<0||newcol>m-1)continue;
                if(image[newrow][newcol]!=start_color)continue;
                if(visited[newrow][newcol]==true)continue;
                q.push({newrow,newcol});
            }
        }
        return image;
    }
};