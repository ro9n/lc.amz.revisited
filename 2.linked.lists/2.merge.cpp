/**
 * @file 2.merge
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday February 16 2021
 *
 * @brief 
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0), *h = dummy;

    while (l1 || l2) {
      if (!l1) {
        h->next = l2;
        break;
      } else if (!l2) {
        h->next = l1;
        break;
      } else if (l1->val < l2->val) {
        h->next = new ListNode(l1->val);
        l1      = l1->next;
      } else {
        h->next = new ListNode(l2->val);
        l2      = l2->next;
      }
      h = h->next;
    }

    return dummy->next;
  }
};
