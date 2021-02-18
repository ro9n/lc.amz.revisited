/**
 * @file 12.cut.off.golf
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday February 07 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define ff first
#define ss second
#define pb push_back

const int del[] = {-1, 0, 1, 0, -1};
const int INF   = 1e9 + 7;

class Solution {
 public:
  int cutOffTree(vector<vector<int>> &mat) {
    int n   = mat.size(),
        m   = mat[0].size(),
        ans = 0;
    vector<ii> trees;

    // pick tree indices
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] > 1) trees.pb({i, j});
      }
    }

    // sort trees
    sort(trees.begin(), trees.end(), [&](const ii &a, const ii &b) {
      return mat[a.ff][a.ss] < mat[b.ff][b.ss];
    });

    auto dist = [&](int sy, int sx, int dy, int dx) {
      if (sy == dy && sx == dx) return 0;

      queue<ii> q;
      int       d = 0,
          color[n][m];

      memset(color, 0x0, sizeof(int) * n * m);
      q.push({sy, sx});
      color[sy][sx] = 1;

      while (!q.empty()) {
        ++d;
        for (int i = 0, n1 = q.size(); i < n1; ++i) {
          int uy = q.front().ff,
              ux = q.front().ss;
          q.pop();

          for (int k = 0; k < 4; ++k) {
            int vy = uy + del[k],
                vx = ux + del[k + 1];

            if (vy < 0 || vy >= n || vx < 0 || vx >= m || !mat[vy][vx] || color[vy][vx]) continue;
            else if (vy == dy && vx == dx)
              return d;
            else {
              color[vy][vx] = 1;
              q.push({vy, vx});
            }
          }
        }
      }

      return INF;
    };

    // cut off
    for (int i  = 0,
             n  = trees.size(),
             sy = 0,
             sx = 0;
         i < n; ++i) {
      int dy  = trees[i].ff,
          dx  = trees[i].ss,
          nxt = dist(sy, sx, dy, dx);
      sy = dy, sx = dx, mat[sy][sx] = 1;

      if (nxt == INF) return -1;
      else
        ans += nxt;
    }

    return ans;
  }
};