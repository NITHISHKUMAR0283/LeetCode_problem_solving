class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp (n+1,vector<int> (m+1,0));
        for(int i = 1;i<=n ; i++){
            for(int j = 1 ; j<= m ; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    continue;
                }
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i = n, j = m,ans = 0 ;
        
        while(i>0 && j>0){
            while(i>0 &&dp[i-1][j]==dp[i][j])i--;
            while(j>0 && dp[i][j]==dp[i][j-1])j--;
            if(i<=0 || j<=0)break;
            ans++;
            i--;
            j--;
        }
        return ans;
    }
};