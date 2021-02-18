/**
 * @file 9.strstr
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday February 16 2021
 *
 * @brief 
 * Z[i] is the length of the longest substring
 * starting from S[i] which is also a prefix of S
 * 
 * As we iterate over the letters in the string (index i from 1 to n - 1),
 * we maintain an interval [L, R] which is the interval with maximum R 
 * such that 1 ≤ L ≤ i ≤ R and S[L...R] is a prefix-substring 
 * if no such interval exists, just let L  =  R  =  - 1
 * 
 * for(int i = 1, l = 0, r = 0; i < n; ++i) {
 *  if (i <= r) z[i] = min(r - i + 1, z[i - l]);
 *  while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
 *  if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
 * }
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int strStr(string text, string pattern) {
    if (pattern.empty() && text.empty())
      return 0;

    string s = pattern + '$' + text;

    int n = s.size(),
        m = pattern.size(),
        z[n];

    memset(z, 0x0, sizeof(int) * n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
      if (i <= r) z[i] = min(r - i + 1, z[i - l]); // within window
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
      if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }

    for (int i = m + 1; i < n; ++i) if (z[i] == m) {
      return i - (m + 1);
    }

    return -1;
  }
};

