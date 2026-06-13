class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp (n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=m;j++){
                int not_taken = max(dp[i-1][j],dp[i][j-1]);
                int taken = 0;
                if(str1[i-1]==str2[j-1]){
                    taken = 1+dp[i-1][j-1];
                }
                dp[i][j] = max(taken , not_taken);
            }
        }
        int i = n , j = m;
        string ans = "";
        while(i>0 && j>0){
            if(dp[i][j]==dp[i-1][j]){
                
                ans+=str1[i-1];
                i--;
            }
            else if(dp[i][j]==dp[i][j-1]){
                ans+=str2[j-1];
                j--;
            }
            else{
                ans+=str1[i-1];
                i--;
                j--;
            }
            

        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};