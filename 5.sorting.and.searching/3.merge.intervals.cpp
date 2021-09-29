/**
 * @file 3.merge.intervals.cpp
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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    vector<vector<int>>                         ans;

    for (auto in : intervals) {
      q.push({in[0], in[1]});
    }

    while (!q.empty()) {
      ii f = q.top();
      q.pop();

      if (q.empty() || f.ss < q.top().ff) {
        ans.push_back({f.ff, f.ss});
      } else {
        ii s = q.top(); q.pop();
        q.push({f.ff, max(f.ss, s.ss)});
      }
    }

    return ans;
  }
};