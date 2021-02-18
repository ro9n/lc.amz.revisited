/**
@file 1.add.nums
@author Touhid Alam <taz.touhid@gmail.com>
 *
@date Tuesday February 16 2021
 *
@brief 
 */

#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list
struct ListNode {
  int       val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int       c     = 0;
    ListNode *dummy = new ListNode(0),
             *r     = dummy;

    while (l1 || l2 || c) {
      int x = 0, y = 0;
      if (l1) x = l1->val, l1 = l1->next;
      if (l2) y = l2->val, l2 = l2->next;

      int sum = x + y + c;

      r->next = new ListNode(sum % 10), c = sum / 10;
      r = r->next;
    }

    return dummy->next;
  }
};
