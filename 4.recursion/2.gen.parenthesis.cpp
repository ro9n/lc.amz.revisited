/**
 * @file 2.gen.parenthesis.cpp
 * @author Touhid Alam <touhid.alam@icloud.com>
 *
 * @date Monday 13.09.2021
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define ff    first
#define ss    second
#define uset  unordered_set
#define umap  unordered_map
#define WHITE 0
#define GREY  1
#define BLACK 2

typedef vector<int> vi;
typedef vector<vi>  vvi;

typedef pair<int, int> ii;

const int INF = 1e9 + 7, dd[] = {-1, 0, 1, 0, -1};

class Solution {
  vector<string> ans;

  void gen(const string &s, int opn, int cls) {
    if (opn) gen(s + '(', opn - 1, cls + 1);
    if (cls) gen(s + ')', opn, cls - 1);
    if (!opn & !cls) ans.push_back(s);
  }

 public:
  vector<string> generateParenthesis(int n) {
    ans.clear(), gen("", n, 0);
    return ans;
  }
};