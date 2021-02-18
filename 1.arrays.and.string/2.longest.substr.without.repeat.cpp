/**
 * @file 2.longest.substr.without.repeat
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday February 15 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define ff first
#define ss second

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n    = s.size(),
        l    = 0,
        r    = 0,
        best = 0;

    map<int, int> at;

    while (r < n) {
      if (at.count(s[r])) l = max(l, at[s[r]] + 1);
      at[s[r]] = r;
      if (r - l + 1 > best) best = r - l + 1;
      ++r;
    }

    return best;
  }
};
