// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/?envType=problem-list-v2&envId=linked-list



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* mover = dummy;
        mover->next = head;
        int last = -1;
        while(mover!=NULL && mover->next!=NULL && mover->next->next!=NULL){
            if(mover->next->val==mover->next->next->val){
                last = mover->next->val;
                while(mover->next!=NULL && mover->next->val==last){
                    mover->next = mover->next->next;
                }
            }else mover = mover->next;
        }

        return dummy->next;
    }
};