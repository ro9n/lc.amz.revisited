/**
 * @file 5.cc
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday February 04 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int dp[amount + 1];

    memset(dp, 0x3f, sizeof(int) * (amount + 1));

    dp[0] = 0;

    for (int k = 1; k <= amount; ++k) {
      for (auto c : coins) {
        if (k >= c)
          dp[k] = min(dp[k], 1 + dp[k - c]);
      }
    }

    return dp[amount] == INF ? -1 : dp[amount];
  }
};
