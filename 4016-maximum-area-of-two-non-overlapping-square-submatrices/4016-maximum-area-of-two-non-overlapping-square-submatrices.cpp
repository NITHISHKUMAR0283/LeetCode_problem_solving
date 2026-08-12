class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int r  = mat.size();
        int c = mat[0].size();
        vector<vector<int>> dp (r+1,vector<int> (c+1,0));
        vector<vector<bool>> row (r+1,vector<bool>(c+1,0));
        vector<vector<bool>> col (c+1,vector<bool>(r+1,0));
        for(int i = 1;i<=r;i++){
            for(int j = 1;j<=c;j++){
                if(mat[i-1][j-1]==1){
                    dp[i][j] = 1+(min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])));
                    row[i][dp[i][j]]=true;
                    col[j][dp[i][j]]=true;
                }            }        }
        for(int i=r-1;i>=1;i--){
            for(int j = 1;j<=min(r,c);j++){
                row[i][j]=row[i][j]||row[i+1][j];
            }        }
        for(int j = c-1; j>0;j--){
            for(int i =1 ; i<=min(r,c);i++){
                col[j][i] = col[j][i] || col[j+1][i];
            }        }
        int res = 0;
        for(int i = 1;i<=r;i++){
            for(int j =1 ;j<=c;j++){
                int fi = i+dp[i][j];
                if(fi<=r && row[fi][dp[i][j]]==true){
                    res = max(res,dp[i][j]);
                }
                int fj = j+dp[i][j];
                if(fj<=c && col[fj][dp[i][j]]==true){
                    res = max(res,dp[i][j]);
                }
            }
        }
        return res*res;
    }
};