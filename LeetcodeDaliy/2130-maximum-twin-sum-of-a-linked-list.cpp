
// LeetCode Daily: 2026-06-14
// Problem: 2130. Maximum Twin Sum of a Linked List
// URL: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description
// Difficulty: MEDIUM

// ==================== C++ SOLUTION ====================

// optimal
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

//  Tc-O(2n), sc-O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next; 
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow; // we are at the start of second part of linked list
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        int ans = 0;
        while(head!=NULL && prev!=NULL){
            ans=max(ans,head->val+prev->val);
            head=head->next;
            prev=prev->next;
        }
        return ans;
    }
};

// brute force 
// Tc-O(2n) , Sc-O(n)

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;
        int ans = 0;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        int n = arr.size();
        for(int i=0;i<=(n/2)-1;i++){
            ans=max(ans,arr[i]+arr[n-i-1]);
        }
        return ans;
    }
};