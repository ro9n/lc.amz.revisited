/**
 * @file 3.buy.sell.stock.I.cpp
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
  int maxProfit(vector<int>& prices) {
    // look for minium budget
    // if already bought look for max sell
    int budget = INF, profit = 0;

    for (auto price : prices) {
      if (price < budget) budget = price;
      if (price - budget > profit) {  // potential profit
        profit = price - budget;      // sell at this price
      }
    }
    return profit;
  }
};