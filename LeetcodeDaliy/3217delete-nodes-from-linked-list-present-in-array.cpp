
// link :-https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
// TYPE:- medium
// name :- 3217. Delete Nodes From Linked List Present in Array

// /tc - O(n*log(n))
// C++
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mpp;
        for(auto i : nums) mpp[i]++;

        ListNode* mover = new ListNode();
        mover->next = head;
        head = mover;
        while(mover!=NULL && mover->next!=NULL){
            if(mpp.find(mover->next->val)!=mpp.end()){
                if(mover->next->next!=NULL){
                    mover->next = mover->next->next;
                }else mover->next = NULL;
            }else mover = mover->next;
        }

        return head->next;
    }
};


// java
