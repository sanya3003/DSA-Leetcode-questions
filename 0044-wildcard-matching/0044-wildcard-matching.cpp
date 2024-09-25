class Solution {
private:
    bool solveTab(string s,string p)
    {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        dp[0][0]=true;

        for(int j=1;j<=m;j++)
        {
            bool flag=true;
            for(int k=1;k<=j;k++)
            {
                if(p[k-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //match
                if(s[i-1]==p[j-1] || p[j-1]=='?')  dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') 
                     dp[i][j]= ( dp[i-1][j]|| dp[i][j-1]);
                else dp[i][j]=false;
            }
        }

        return dp[n][m];
    }
public:
    bool isMatch(string s, string p) {

         return solveTab(s,p);

    }
};