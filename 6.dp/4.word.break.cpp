/**
 * @file 4.word.break
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday February 06 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

struct trie {
  bool lf;
  struct trie* nxt[26];

  void insert(string w) {
    auto r = this; for (auto c: w) {
      if (!r->nxt[c - 97]) r->nxt[c - 97] = new trie();
      r = r->nxt[c - 97];
    }
    r->lf = 1;
  }
};

class Solution {
 public:
  bool wordBreak(string s, vector<string>& dict) {
    int n = s.size(), color[n]; memset(color, 0x0, sizeof(int)*n);

    trie *r = new trie(); for(auto w: dict) r->insert(w);

    queue<int> q; q.push(0); while(!q.empty()) {
      int front = q.front(); q.pop();

      if (front == n) return 1;
      else if (color[front]) continue;

      color[front] = 0x1;

      auto *h = r; for(int i = front; i < n && h; ++i) {
        h = h->nxt[s[i] - 97];
        if (h && h->lf && !color[i]) q.push(i + 1);
      }
    }

    return 0;
  }
};
