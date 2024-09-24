class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i == 0) return j;
        if(j==0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]) return dp[i][j] =  f(i-1, j-1, s1, s2, dp);
        return dp[i][j] =  1+ min(f(i-1, j, s1, s2, dp), min(f(i,j-1, s1, s2, dp), f(i-1,j-1, s1, s2, dp)));

    }
    int minDistance(string str1, string str2) {
        int n = str1.size();
    int m = str2.size();

    // Create a DP table to store edit distances
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row and column
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    // Fill in the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                // If the characters match, no additional cost
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    // The value at dp[n][m] contains the edit distance
    return dp[n][m];
}
};