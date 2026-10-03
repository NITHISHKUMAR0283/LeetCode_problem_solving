class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;

        int[][][] dp = new int[n][3][2];

        // Python uses -1 initialization
        for (int i = 0; i < n; i++) {
            for (int transactions = 0; transactions < 3; transactions++) {
                for (int canbuy = 0; canbuy < 2; canbuy++) {
                    dp[i][transactions][canbuy] = -1;
                }
            }
        }

        int max_profit = explore(prices, 1, 0, dp, 0);
        return max_profit;
    }

    public int explore(int[] prices, int canbuy, int transactions,
                       int[][][] dp, int i) {

        if (transactions >= 2 || i >= prices.length) {
            return 0;
        }

        if (dp[i][transactions][canbuy] != -1) {
            return dp[i][transactions][canbuy];
        }

        int buy = Integer.MIN_VALUE;

        if (canbuy == 1) {
            buy = explore(prices, 0, transactions, dp, i + 1)
                    - prices[i];
        }

        int sell = Integer.MIN_VALUE;

        if (canbuy == 0) {
            sell = explore(prices, 1, transactions + 1, dp, i + 1)
                    + prices[i];
        }

        int hold = explore(prices, canbuy, transactions, dp, i + 1);

        dp[i][transactions][canbuy] =
                Math.max(buy, Math.max(sell, hold));

        return dp[i][transactions][canbuy];
    }
}