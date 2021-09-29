/**
 * @file 2.max.subarray.cpp
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
  int maxSubArray(vector<int>& nums) {
    int best = nums[0], n = nums.size();
    for (int i = 1, sum = nums[0]; i < n; ++i) {
      sum  = max(nums[i], sum + nums[i]);
      best = max(best, sum);
    }
    return best;
  }
};