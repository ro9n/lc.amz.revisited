/**
 * @file 7.3sum
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
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    int n = nums.size();

    for (int i = 0; i < n && nums[i] <= 0; ++i) {
      if (i > 0 && nums[i - 1] == nums[i]) continue;
      for (int l = i + 1, r = n - 1; l < r;) {
        int sum = nums[i] + nums[l] + nums[r];

        if (sum < 0) ++l;
        else if (sum > 0)
          --r;
        else {
          ans.push_back({nums[i], nums[l++], nums[r--]});
          while (l < r && nums[l - 1] == nums[l]) ++l;
        }
      }
    }

    return ans;
  }
};
