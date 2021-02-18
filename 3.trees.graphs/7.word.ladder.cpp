/**
 * @file 7.word.ladder
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday February 13 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define uset unordered_set

class Solution {
 public:
  int ladderLength(string b, string e, vector<string>& dict) {
    uset<string> s(dict.begin(), dict.end());

    queue<string> q; q.push(b); int d = 1;

    while (!q.empty()) {
      for (int i = 0, n = q.size(); i < n; ++i) {
        string u = q.front(); q.pop();

        if (u == e) return d;

        for (int j = 0, m = u.size(); j < m; ++j) {
          int c = u[j];

          for(int k = 0; k < 26; ++k) if (k + 97 != c) {
            u[j] = k + 97;
            if (s.count(u)) q.push(u), s.erase(u);
          }

          u[j] = c;
        }
      }
      ++d;
    }

    return 0;
  }
};