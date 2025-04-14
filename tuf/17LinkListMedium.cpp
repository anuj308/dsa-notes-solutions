#include <bits/stdc++.h>
using namespace std;
// ---------
ListNode* middleNode(ListNode* head) {
    vector<int> store;
    ListNode* mover = head;
    while(mover->next!=NULL){
        store.push_back(mover->val);
        mover = mover->next;
    }
    store.push_back(mover->val);
    int mid = (store.size()/2) +  1;
    int c=1;
    mover=head;
    while(mover->next!=NULL){
        if(c==mid){
            return mover;
        }
        c++;
        mover=mover->next;
    }
    return mover;
}
ListNode* reverseList(ListNode* head) {
    if(head==NULL) return head;
    ListNode* mover = head;
    vector<int> store;
    while(mover->next!=NULL){
        store.push_back(mover->val);
        mover=mover->next;
    }
    store.push_back(mover->val);
    mover = head;
    while(mover->next!=NULL){
        int data = store.back();
        mover->val = data;
        store.pop_back();
        mover=mover->next;
    }
    int data = store.back();
    mover->val = data;
    store.pop_back();
    return head;
}
bool hasCycle(ListNode *head) {
    if( head==NULL || head->next == NULL) return false;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(slow!=fast){
        if(fast == NULL || fast->next == NULL) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
bool hasCycle(ListNode *head) {
    // tc - O(n) + O(n)worst or O(1) averge, sc - O(N);
    unordered_map<ListNode*,int> mpp;

    ListNode *temp = head;
    while(temp->next!=NULL){
        if(mpp.find(temp)!=mpp.end()){
            return true;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return false;
}
ListNode *detectCycle(ListNode *head) {
    if(head==NULL) return NULL;
    unordered_map<ListNode*,int> mpp;
    ListNode* mover = head;
    while(mover->next!=NULL){
        if(mpp.find(mover)!=mpp.end()){
            return mover;
        }
        mpp[mover]=1;
        mover=mover->next;
    }
    return NULL;
}
ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        
    }
    return NULL;
}
int countNodesinLoop(Node *head) {
    // Code here
    Node* slow = head;
    Node* fast = head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            // now slow and fast is in the start of loop
            int c =0;
            fast=fast->next;
            c+=1;
            while(slow!=fast){
                fast=fast->next;
                c++;
            }
            return c;
        }
    }
    return 0;
}
bool isPalindrome(ListNode* head) {
    vector<int> store;
    ListNode* mover = head;
    while(mover->next!=NULL){
        store.push_back(mover->val);
        mover=mover->next;
    }
    store.push_back(mover->val);
    int n = store.size();
    for(int i=0;i<n/2;i++){
        if(store[i]!=store[n-1-i]){
            return false;
        }
    }
    return true;
}
ListNode* oddEvenList(ListNode* head) {
    vector<int> storeEven;
    vector<int> storeOdd;
    ListNode* temp = head;
    int c = 1;
    while(temp!=NULL){
        if(c%2!=0) storeOdd.push_back(temp->val);
        else storeEven.push_back(temp->val);
        c++;
        temp=temp->next;
    }
    temp = head;
    c=1;
    int odd=0;
    int even=0;
    while(temp!=NULL){
        if(c<=storeOdd.size()){
            temp->val = storeOdd[odd];
            odd++;
        }else{
            temp->val = storeEven[even];
            even++;
        }
        c++;
        temp=temp->next;
    }
    return head;
}
ListNode* removeNthFromEnd(ListNode* head, int n) { // tc - O(2N) , sc - O(N)
    if(head->next==NULL && n==1) return NULL;

    int c=0;
    ListNode* mover = head;
    while(mover!=NULL){
        c++;
        mover=mover->next;
    }
    int remove = c - n; // index behind remove or removeINdex - 1
    if(remove==0){ // remove first index
        return head->next;
    }
    c=1;
    mover=head;
    while(mover!=NULL){
        if(c==remove){
            ListNode* temp = mover->next;
            if(mover->next->next!=NULL) mover->next=mover->next->next;
            else mover->next=NULL;
            delete temp;
            break;
        }
        c++;
        mover=mover->next;
    }
    return head;
}
ListNode* deleteMiddle(ListNode* head) {
    ListNode* mover = head;
    int c=0;
    while(mover!=NULL){
        c++;
        mover=mover->next;
    }
    mover = head;
    int i = 0;
    if(c/2==0){
        if(head->next!=NULL) return head->next;
        return NULL;
    }
    while(mover!=NULL){
        if(i==(c/2)-1){
            ListNode* temp = mover->next;
            if(mover->next!=NULL && mover->next->next!=NULL) mover->next=mover->next->next;
            else mover->next=NULL;
            delete temp;
            break; 
        }
        mover=mover->next;
        i++;
    }

    return head;
}
ListNode* deleteMiddle(ListNode* head) {
    if(head->next==NULL) return NULL;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    // cout  << slow->val;
    ListNode* temp = slow->next;
    if(slow->next!=NULL && slow->next->next!=NULL) slow->next=slow->next->next;
    else slow->next = NULL;
    delete temp;

    return head;
}
Node* segregate(Node* head) { // 
    int store0=0;
    int store1=0;
    int store2=0;
    Node* mover = head;
    while(mover!=NULL){
        if(mover->data==0) store0++;
        if(mover->data==1) store1++;
        if(mover->data==2) store2++;
        mover=mover->next;
    }
    mover=head;
    while(mover!=NULL){
        if(store0>0){ 
            store0--; 
            mover->data=0;
        }
        else if(store1>0){
            store1--;
            mover->data=1;
        }else {
            mover->data=2;
            store2--;
        }
        mover=mover->next;
    }
    return head;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // tc - O(n) + O(m^2)(worst case) , sc - O(n+m)
    unordered_map<ListNode*,int> mpp;
    ListNode* mover = headA;
    while(mover!=NULL){
        mpp[mover]++;
        mover=mover->next;
    }
    mover = headB;
    while(mover!=NULL){
        if(mpp.find(mover)!=mpp.end()){
            return mover;
        }
        mover=mover->next;
    }
    return NULL;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // tc - O(2N) sc - O(1)
    ListNode* m1 = headA;
    ListNode* m2 = headB;
    int a=0;
    int b=0;
    while(m1!=NULL){
        a++;
        m1=m1->next;
    }
    while(m2!=NULL){
        b++;
        m2=m2->next;
    }
    m1=headA;
    m2=headB;
    if(a>b){
        for(int i=0;i<a-b;i++){
            m1=m1->next;
        }
    }else{
        for(int i=0;i<b-a;i++){
            m2=m2->next;
        }
    }
    // both are at equal start point
    while(m1!=NULL && m2!=NULL){
        if(m1==m2){
            return m1;
        }
        m1=m1->next;
        m2=m2->next;
    }
    return NULL;
}
void fun(Node*& head,int c){
    Node* mover = head;
    int i =0;
    if(c==0){
        Node* temp = new Node(1);
        head->data=0;
        temp->next = head;
        head = temp;
        return;
    }
    while(mover!=NULL){
        if(i==c-1){
            if((mover->data + 1 )== 10){ 
                mover->data=0;
                fun(head,i);
            }else{
                mover->data = mover->data + 1;
            }
        }
        i++;
        mover=mover->next;
    }
}
Node* addOne(Node* head) {
    // Your Code here
    // return head of list after adding one
    Node* mover = head;
    int c=0;
    while(mover->next!=NULL){
        c++;
        mover=mover->next;
    }
    if((mover->data + 1 )== 10){ 
        fun(head,c+1);
    }else{
        mover->data = mover->data + 1;
    }
    return head;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* m1 = l1;
    ListNode* m2 = l2;
    ListNode* ans = new ListNode(0);
    ListNode* a1 = ans;
    int carry = 0;
    while(m1!=NULL || m2!=NULL){
        ListNode* temp = new ListNode(0);
        int add = 0;
        if(m1!=NULL && m2!=NULL){
            add = m1->val+m2->val+carry;
        }else if(m1!=NULL && m2==NULL){
            add = m1->val+carry;
        }else{
            add = m2->val+carry;
        }
        carry=0;
        if( add > 9){
            temp->val = add % 10;
            carry = add/10;
        }
        else temp->val = add;
        a1->next=temp;
        if(m1!=NULL) m1=m1->next;
        if(m2!=NULL) m2=m2->next;
        a1=a1->next;
    }
    if(carry!=0){
        ListNode* temp = new ListNode(carry);
        a1->next=temp;
    }
    return ans->next;
}
ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL) return head;
    ListNode* mover = head;
    while(mover!=NULL){
        if(mover->next!=NULL && mover->next->val==val){
            ListNode* start = mover;
            ListNode* temp = mover->next;
            if(mover->next->next!=NULL) mover->next = mover->next->next;
            else mover->next = NULL;
            delete temp;
            while(mover->next!=NULL && mover->next->val==val){
                ListNode* temp = mover->next;
                if(mover->next->next!=NULL) start->next=mover->next->next;
                else start->next=NULL;
                delete temp;
                mover = start;
            }
        }
        mover=mover->next;
    }
    if(head->val==val) return head->next;
    return head;
} // beats 5% tc - O(N)
ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL) return head;
    ListNode* mover = head;
    ListNode* start = head;

    while(mover->next!=NULL){
        if(mover->next->val==val){
            ListNode* temp = mover->next;
            if(mover->next->next!=NULL) start->next=mover->next->next;
            else start->next=NULL;
            delete temp;
            mover = start;
        }else{
            mover=mover->next;
            start=start->next;
        }
    }
    if(head->val==val) return head->next;
    return head;
} // beats 100% more optimised from the above one tc = O(n)
Node * deleteAllOccurrences(Node* head, int k) {
    while(head!=NULL && head->data==k){
        Node* temp = head;
        head = head->next;
        if(head) head->prev = NULL;
        delete temp;
    }

    Node* mover = head;
    while(mover!=NULL && mover->next!=NULL){
        if(mover->next->data==k){
            Node* temp = mover->next;
            if(mover->next->next!=NULL){
                mover->next = mover->next->next;
                mover->next->next->prev = mover;
            }
            else mover->next = NULL;
            delete temp;
        }else{
            mover=mover->next;
        }
    }
    return head;
}
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
    Node* start = head;
    Node* end = head;
    int s=0;
    int e=0;
    while(end->next!=NULL){
        e++;
        end = end->next;
    }
    vector<pair<int,int>> ans;
    while(s<e){
        if(start->data+end->data == target){
            ans.push_back({start->data,end->data});
            start=start->next;
            s++;
            end=end->prev;
            e--;
        }
        else if(start->data+end->data > target){
            e--;
            end= end->prev;
        }else{
            s++;
            start=start->next;
        }
    }
    return ans;
}
Node * removeDuplicates(struct Node *head)
{
    // Your code here
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* mover = head;
    while(mover!=NULL && mover->next!=NULL){
        if(mover->data==mover->next->data){
            Node* temp = mover->next;
            mover->next=mover->next->next;
            if(mover->next!=NULL) mover->next->prev = mover;
            temp->prev=NULL;
            temp->next=NULL;
            delete temp;
        }else{
            mover=mover->next;
        }
    }
    return head;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    int c=1;
    ListNode* mover = head;
    ListNode* m2 = new ListNode(0);
    head = m2;
    vector<ListNode*> store;
    while(mover!=NULL){
        store.push_back(mover);
        mover=mover->next;
        if(store.size()==k){
            while(!store.empty()){
                ListNode* temp = store.back();
                store.pop_back();
                m2->next = temp;
                m2 = m2->next;
                m2->next = NULL; // very imp 
            }
        }
        c++;
    }
    int s = store.size();
    c=0;
    while(c<s){ // node left in store add them
        ListNode* temp = store[c];
        m2->next = temp;
        m2 = m2->next;
        m2->next=NULL;
        c++;
    }
    return head->next;
} // tc - O(n), sc - O(1)
ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL || k==0) return head;
    int c=0;
    ListNode* mover = head;
    ListNode* end;
    while(mover!=NULL){
        if(mover->next==NULL) end = mover;
        mover=mover->next;
        c++;
    }
    int st;
    if(c>k) st = c - k;
    if(k%c==0) return head;
    if(k>=c) {
        st = k % c;
        st = c - st;
    }
    c=1;
    mover = head;
    while(mover!=NULL){
        if(c==st){
            ListNode* temp = mover->next;
            mover->next=NULL;
            end->next = head;
            head = temp;
            break;
        }
        mover=mover->next;
        c++;
    }
    return head;
}
Node* flattenLinkedList(Node* head) 
{
	
	Node* mover = head;
	vector<int> store;
	while(mover!=NULL){
		Node* m2 = mover;
		while(m2!=NULL){
			store.push_back(m2->data);
			m2=m2->child;
		}
		mover=mover->next;
	}
	mover = head;
	sort(store.begin(),store.end());
	for(auto h : store){
		mover->child = new Node(h);
		mover=mover->child;
	}
	return head->child;
}
Node* copyRandomList(Node* head) {
    Node* m = new Node(0);
    Node* ans = m;
    Node* mover = head;
    vector<Node*> store; // for new nodes
    unordered_map<Node*,int> mpp; // original nodes
    int c=0;
    while(mover!=NULL){
        Node* temp = new Node(mover->val);
        ans->next = temp;
        ans=ans->next;
        store.push_back(temp);
        mpp[mover]=c;
        c++;
        mover=mover->next;
    }
    mover = head;
    ans=m->next;
    while(mover!=NULL){
        if(mover->random==NULL) ans->random = NULL;
        else ans->random = store[mpp[mover->random]]; // seraching for index of random nodes and then putting random node of new nodes for store with new nodes
        ans=ans->next;
        mover=mover->next;
    }
    return m->next;
}
int main(){
    return 0;
}