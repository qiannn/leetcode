#Best Time to Buy and Sell Stock IV

``` cpp
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int days = prices.size();
        if (days <= 1) return 0;
        
        if (k > days/2) {
            int profit = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }
        
        vector<vector<int> > dp(days, vector<int>(k + 1, 0));
        vector<vector<int> > local(days, vector<int>(k + 1, 0));
        for (int j = 1; j <= k; ++j) {
            for (int i = 1; i < days; ++i) {
                int diff = prices[i] - prices[i-1];
                local[i][j] = max(dp[i-1][j-1] + max(diff, 0),
                                  local[i-1][j] + diff);
                dp[i][j] = max(dp[i-1][j], local[i][j]);
            }
        }
        return dp[days - 1][k];
    }
    
    int max(int x, int y) {
        return x > y ? x : y;
    }
};
```

##解题思路：
very hard 的一道题，看了一天才勉强看懂别人的思路。**难点主要是动态转移方程的构造。**

首先，思路仍然和之前三道题一样是动态规划，构造二维数组dp[d][t]，表示前d天最多进行了t次交易，从t次交易中获取的最大利润。

状态转移方程如下：

```
diff = price[i] - price[i-1]
dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + diff);
```

看起来很直观，就是正常的动态规划方程，可是这个方程存在一个问题。

如下图所示：在确定dp[i][j]的过程时，如果第i天没有参与交易（无交易在第i天结束），那么dp[i][j] = dp[i-1][j]，如果有交易在第i天结束，那么dp[i][j]其实不一定等于dp[i-1][j-1] + diff的。有一次交易在i-1天结束，交易利润S2小于S1导致dp[i-1][j-1] = S1,如果第i天也有交易结束，也就是第i-1
天买进，第i天卖出，那么实际上产生的利润值diff应该合并到S2中，并将两次交易看成一次交易。**结论就是第i天如果产生了交易，那么需要考虑第i-1天是否有卖出股票的情况**

再设计一个数组local[d][t]，表示在第d天卖出股票的情况下，进行t此交易可以产生的最大利润。

```
local[i][j] = max(dp[i-1][j-1] + max(diff, 0), local[i-1][j]+diff);
```

**dp[i-1][j-1] + max(diff, 0)**表示i-1天没有发生交易，那么第i天卖出的必然是第i-1或是第i天的股票，这里需要判断diff是否为正，即**[i-1~i]**是否赚钱；**local[i-1][j]+diff**表示第i-1天进行了第j次交易，**[i-1~i]**这个交易需要和之前一段交易即S2合并成S2'，这样保证了第i天进行了交易，且交易次数不超过j次。