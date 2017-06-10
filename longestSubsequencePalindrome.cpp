//https://codefights.com/interview/GzsDgPvrKLtvbM5Qk/description
//frankr@coj

int longestSubsequencePalindrome(std::vector<int> a) {
    int n = a.size();
    int dp[n][n];
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            dp[i][j] = 0;
    
    for (int i = 0 ; i < n ; i++)
        dp[i][i] = 1;
    
    for (int i = 1 ; i < n ; i++)
        if (a[i - 1] == a[i])
            dp[i - 1][i] = 2;
        else
            dp[i - 1][i] = 1;
    
    for (int L = 3 ; L <= n ; L++){
        for (int pos = 1 ; pos <= n - L + 1 ; pos++){
            int i = pos - 1;
            int j = i + L - 1;
            if (a[i] == a[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[0][n - 1];
}
