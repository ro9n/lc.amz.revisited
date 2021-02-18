/**
 * @file 3.stock
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday February 06 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5 + 7;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int best = 0, buy = INF;
    
    for(auto p: prices) {
      if (p < buy) buy = p;
      else if (p - buy > best) best = p - buy;
    }

    return best;
  }
};
