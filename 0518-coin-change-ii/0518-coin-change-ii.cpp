class Solution {
public:
int knapsack(vector<int>&coins,int amount){
    const long long MOD = 1000000007;
    int n=coins.size();
    vector<vector<long long>>dp(n+1,vector<long long>(amount+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=amount;j++){
          if(coins[i-1]<=j)  dp[i][j] = min(
                        2147483647LL,
                        dp[i][j - coins[i - 1]] + dp[i - 1][j]
                    );
          else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][amount];
}
    int change(int amount, vector<int>& coins) {
        return knapsack(coins,amount);
    }
};