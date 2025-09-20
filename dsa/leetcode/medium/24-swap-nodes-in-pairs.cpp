//  problem link :- https://leetcode.com/problems/swap-nodes-in-pairs/description/
//  name :=  24. Swap Nodes in Pairs
//  dificulty : - medium

// c++ code
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
        ListNode* mover = new ListNode(0);
        mover->next=head;
        head=mover;
        while(mover!=NULL){
            if(mover->next!=NULL){
                ListNode* temp = new ListNode(mover->next->val,mover->next);
                if(mover->next->next!=NULL && mover->next->next->next!=NULL) temp->next = mover->next->next->next;
                else temp->next = NULL;
                if(mover->next->next!=NULL){
                    mover->next = mover->next->next;
                    mover=mover->next;
                    mover->next = temp;
                    mover=mover->next;
                }else if(mover->next!=NULL){
                    mover->next = temp;
                    mover=mover->next;
                }
            }else break;
        }
        return head->next;
    }
};
