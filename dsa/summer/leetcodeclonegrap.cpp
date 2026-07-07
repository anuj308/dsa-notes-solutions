// https://leetcode.com/problems/clone-graph/
Node* cloneGraph(Node* node) {
    if(!node) return node;
    Node* ans = new Node(-1);
    Node* mover = ans;
    queue<pair<Node*,Node*>> q;
    q.push({node,mover});
    unordered_map<int,Node*> mpp;
    while(!q.empty()){
        Node* temp = q.front().second;
        Node* ori = q.front().first;
        q.pop();
        if(temp->val==-1){
            temp->val = ori->val;
            mpp[ori->val]=temp;
        }
        for(auto it : ori->neighbors){
            if(mpp.find(it->val)!=mpp.end()){
                temp->neighbors.push_back(mpp[it->val]);
            }else{
                Node* tempNode = new Node(it->val);
                temp->neighbors.push_back(tempNode);
                q.push({it,tempNode});
                mpp[it->val]=tempNode;
            }
        }
    }
    return ans;
}