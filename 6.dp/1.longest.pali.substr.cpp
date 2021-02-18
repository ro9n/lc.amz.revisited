/**
 * @file 1.longest.pali.substr
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday February 05 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
typedef pair<int, int> ii;

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.empty()) return "";

    int n = s.size(),
        dp[n][n];

    ii best = {0, 1};

    memset(dp, 0x0, sizeof(int) * n * n);

    for(int i = n - 1; i >= 0; --i) {
      for(int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = i + 1 >= j - 1 ? 1 : dp[i + 1][j - 1];
          if (dp[i][j] && j - i + 1 > best.ss) best = {i, j - i + 1}; 
        }
      }
    }

    return s.substr(best.ff, best.ss);
  }
};
