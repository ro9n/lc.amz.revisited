/**
 * @file 6.word.ladder.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday February 14 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define uset unordered_set
#define umap unordered_map

const int INF = 1e9 + 7;

struct ladder {
  uset<string>   s;
  vector<string> v;

  ladder(string w) {
    insert(w);
  }

  string back() {
    return v.back();
  }

  void insert(string w) {
    v.push_back(w), s.insert(w);
  }

  bool contains(string w) {
    return s.count(w);
  }

  int size() {
    return v.size();
  }

  ladder clone(string w) {
    ladder tmp = ladder(v[0]);
    for(int i = 1; i < size(); ++i) {
      tmp.insert(v[i]);
    }
    tmp.insert(w);
    return tmp;
  }

  bool operator<(const ladder &other) const {
    return v.size() > other.v.size();
  }
};

class Solution {
 public:
  vector<vector<string>> findLadders(
      string          begin_word,
      string          end_word,
      vector<string>& words) {

      int dist = INF; vector<vector<string>> ans;
      uset<string> s(words.begin(), words.end());
      
      if (!s.count(end_word)) return {}; // base case: unreachable

      priority_queue<ladder> q; q.push(ladder(begin_word));

      while (!q.empty()) {
        auto front = q.top(); q.pop();
        string u = front.back();

        if (u == end_word && front.size() <= dist) dist = front.size(), ans.push_back(front.v);

        for(int i = 0, n = u.size(); i < n; ++i) {
          int c = u[i];
          for(int j = 0; j < 26; ++j) if (j + 97 != c) {
            u[i] = j + 97;
            if (s.count(u) 
              && !front.contains(u) 
              && (front.size() < dist || u == end_word)) 
                q.push(front.clone(u));
          }
          u[i] = c;
        }
      }

      return ans;
  }
};