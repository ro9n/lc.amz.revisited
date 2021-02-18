/**
 * @file 5.int.to.roman
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
  string intToRoman(int num) {
    string ans = "";
    while (num) {
      if (num >= 1000)
        ans += "M", num -= 1000;
      else if (num >= 900)  // 2
        ans += "CM", num -= 900;
      else if (num >= 500)
        ans += "D", num -= 500;
      else if (num >= 400)
        ans += "CD", num -= 400;
      else if (num >= 100)
        ans += "C", num -= 100;
      else if (num >= 90)  // 3
        ans += "XC", num -= 90;
      else if (num >= 50)
        ans += "L", num -= 50;
      else if (num >= 40)
        ans += "XL", num -= 40;
      else if (num >= 10)
        ans += "X", num -= 10;
      else if (num >= 9)  // 4
        ans += "IX", num -= 9;
      else if (num >= 5)
        ans += "V", num -= 5;
      else if (num >= 4)
        ans += "IV", num -= 4;
      else if (num >= 1)
        ans += "I", num -= 1;
    }

    return ans;
  }
};
