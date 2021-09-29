/**
 * @file 2.min.stack.cpp
 * @author Touhid Alam <touhid.alam@icloud.com>
 *
 * @date Monday 09.08.2021
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

class MinStack {
 public:
  stack<ii> s;
  /** initialize your data structure here. */
  MinStack() {}

  void push(int v) {
    if (s.empty()) s.push({v, v});
    else {
      int top = s.top().ss;
      s.push({v, min(v, top)});
    }
  }

  void pop() {
    s.pop();
  }

  int top() {
    return s.top().ff;
  }

  int getMin() {
    return s.top().ss;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */