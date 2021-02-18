/**
 * @file 13.version.compare
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday February 16 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int compareVersion(string a, string b) {
    for (int i = 0,
             j = 0,
             n = a.size(),
             m = b.size();
         i < n || j < m; ++i, ++j) {
      int a1 = 0, b1 = 0;
      while (i < n && a[i] != '.') a1 *= 10, a1 += a[i++] - 48;
      while (j < m && b[j] != '.') b1 *= 10, b1 += b[j++] - 48;

      if (a1 < b1) return -1;
      else if (a1 > b1)
        return 1;
    }

    return 0;
  }
};
