/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* first,*second;
      first=list1;
      second=list2;
      if((!list1) and (!list2))
          return nullptr;
      else if((!list1)) return list2;
      else if((!list2)) return list1;
    
      if((first->val)>(second->val))
          return mergeTwoLists(list2,list1);
      while((first) and (second))
      {
          if((first->next) and first->next->val>second->val)
          {
              ListNode *tmp=second->next;
              second->next=first->next;
              first->next=second;
              second=tmp;
              first=first->next;
          }
          else if((!first->next))
          {
            first->next=second;    
            break;
          }
          else
              first=first->next;
      }
      return list1;
    }
};