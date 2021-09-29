/**
 * @file 4.word.break.revisited.cpp
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
  bool wordBreak(string s, vector<string>& dict) {
    uset<string> S(dict.begin(), dict.end());
    int          n = s.size(), dp[n + 1];
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] & S.count(s.substr(j, i - j))) dp[i] = 1;
      }
    }

    return dp[n];
  }
};