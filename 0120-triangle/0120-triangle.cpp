class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp (n,vector<int>(m,0));
        int  j = 1;
        dp[0][0]= triangle[0][0];
        for(int i = 1;i<n;i++){
            dp[i][0]=triangle[i][0]+dp[i-1][0];
            dp[i][j]=triangle[i][j]+dp[i-1][j-1];
            j++;
        }
        for(int i = 2 ;i<n;i++){
            for(int j = 1;j<triangle[i].size()-1;j++){
                dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};