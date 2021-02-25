class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 允许多次交易，并且盈利之后手上可以买入后面更高价格的股票
        // 动态规划，需要两个状态方程
        // 1. 第i天手上没有股票的最大利润 = max(前一天没有股票的利润, 前一天有股票+今天卖出) dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])
        // 2. 第i填手上有股票的最大利润 = max(前一天有股票的利润，前一天没有股票-买入的价格) dp[i][1] = max(dp[i-1][1], dp[i-1][0] - price[i])
        // 最后的结果肯定是dp[i][0] > dp[i][1]，因为交易结束取dp[i][0]？这个待商榷

        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i<n-1; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n][0];

    }
};