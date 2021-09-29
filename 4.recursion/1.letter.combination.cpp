/**
 * @file 1.letter.combination.cpp
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

const string t9[] = {"",    "",    "abc",  "def", "ghi",
                     "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
  vector<string> ans;
  void           collect(const string &s, const string t, int i) {
    int n = s.size();
    if (i == n) {
      if (t.size()) ans.push_back(t);
    } else {
      for (auto c : t9[s[i] - 48]) {
        // 3ᴺ*4ᴹ
        collect(s, t + c, i + 1);
      }
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    ans.clear(), collect(digits, "", 0);
    return ans;
  }
};