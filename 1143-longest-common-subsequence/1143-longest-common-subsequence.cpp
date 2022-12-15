int dp[1001][1001];
int solve(string &text1,string &text2,int m,int n)
{
    if(text1[m-1]=='\0' || text2[n-1]=='\0')
        return 0;
    else if(text1[m-1]==text2[n-1])
    {
        return 1+dp[m-1][n-1];
    }
    else
        return max(dp[m-1][n],dp[m][n-1]);
}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
        
        
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=solve(text1,text2,i,j);
            }
        }
        return dp[m][n];
    }
};