/**
 * @file 5.coin.change.cpp
 * @author Touhid Alam <touhid.alam@icloud.com>
 *
 * @date Sunday 08.08.2021
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map

typedef vector<int> vi;
typedef vector<vi>  vvi;

typedef pair<int, int> ii;

const int INF = 1e9 + 7, dd[] = {-1, 0, 1, 0, -1};

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size(), dp[amount + 1];

    memset(dp, 0x3f, sizeof(int) * (amount + 1));
    dp[0] = 0;  // 1 empty way to get 0

    for (int change = 1; change <= amount; ++change) {
      for (auto c : coins) {
        if (c <= change) {
          dp[change] =
              min(dp[change],         // itself
                  dp[change - c] + 1  // min to get without this coin + 1
              );
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
};