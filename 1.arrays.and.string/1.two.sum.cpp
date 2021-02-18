/**
 * @file 1.two.sum
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday February 15 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> comp;

    for(int i = 0, n = nums.size(); i < n; ++i) {
      if (comp.count(target - nums[i])) return {comp[target - nums[i]], i};
      else comp[nums[i]] = i;
    }

    return {-1, -1};
  }
};
