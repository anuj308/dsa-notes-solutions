// https://leetcode.com/problems/search-in-a-binary-search-tree/description/
TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != NULL && root->val != val)
    {
        root = val < root->val ? root->left : root->right;
    }
    return root;
}

// found this while .. https://leetcode.com/problems/maximum-binary-tree/
TreeNode *ans(TreeNode *root, int start, int end, vector<int> &nums)
{
    if (start > end)
        return NULL;
    int maxInd = start;
    int maxVal = 0;
    for (int i = start; i <= end; i++)
    {
        if (nums[i] > maxVal)
        {
            maxVal = nums[i];
            maxInd = i;
        }
    }
    root->val = maxVal;
    TreeNode *left = new TreeNode();
    root->left = left;
    TreeNode *right = new TreeNode();
    root->right = right;
    if (ans(left, start, maxInd - 1, nums) == NULL)
        root->left = NULL;
    if (ans(right, maxInd + 1, end, nums) == NULL)
        root->right = NULL;
    return root;
}
TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    TreeNode *root = new TreeNode();
    int n = nums.size();
    return ans(root, 0, n - 1, nums);
}

// https://www.naukri.com/code360/problems/minimum-element-in-bst_8160462
int minVal(Node *root)
{
    if (root == NULL)
        return -1;
    int min = INT_MAX;
    while (root != NULL)
    {
        if (root->data < min)
        {
            min = root->data;
            root = root->left;
        }
        else
        {
            min = root->data;
            root = root->right;
        }
    }
    return min;
}

// https://www.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1
int findMax(Node *root)
{
    int max = INT_MIN;
    while (root != NULL)
    {
        max = root->data;
        root = root->right;
    }
    return max;
}

int findMin(Node *root)
{

    int min = INT_MAX;
    while (root != NULL)
    {
        min = root->data;
        root = root->left;
    }
    return min;
}

// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
int findCeil(Node *root, int input)
{
    // Your code here
    int ans = -1;
    while (root != NULL)
    {
        if (root->data >= input)
        {
            ans = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;
}
// https://www.geeksforgeeks.org/problems/floor-in-bst/1
int floor(Node *root, int x)
{
    int ans = -1;
    while (root != NULL)
    {
        if (root->data <= x)
        {
            ans = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return ans;
}

// https://leetcode.com/problems/insert-into-a-binary-search-tree/
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode *ans = new TreeNode(val);
    if (root == NULL)
        return ans;

    TreeNode *mover = root;
    while (mover != NULL)
    {
        if (mover->val < val)
        {
            if (mover->right == NULL)
            {
                mover->right = ans;
                break;
            }
            mover = mover->right;
        }
        else
        {
            if (mover->left == NULL)
            {
                mover->left = ans;
                break;
            }
            mover = mover->left;
        }
    }

    return root;
}

// https://leetcode.com/problems/delete-node-in-a-bst/submissions/1726777351/
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return root;
    if (root->val == key)
        return helper(root);
    TreeNode *mover = root;
    while (mover != NULL)
    {
        if (mover->val > key)
        {
            if (mover->left != NULL && mover->left->val == key)
            {
                mover->left = helper(mover->left);
            }
            else
            {
                mover = mover->left;
            }
        }
        else
        {
            if (mover->right != NULL && mover->right->val == key)
            {
                mover->right = helper(mover->right);
            }
            else
            {
                mover = mover->right;
            }
        }
    }
    return root;
}
TreeNode *helper(TreeNode *root)
{
    if (root->left == NULL)
        return root->right;
    if (root->right == NULL)
        return root->left;
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = lastRightOfLeft(root->left);
    lastRight->right = rightChild;
    return root->left;
}
TreeNode *lastRightOfLeft(TreeNode *root)
{
    if (root->right == NULL)
        return root;
    return lastRightOfLeft(root->right);
}
//   https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// brute forces
int kthSmallest(TreeNode *root, int k)
{
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            ans.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    sort(ans.begin(), ans.end());
    return ans[k - 1];
}

// optimised - in bst inorder give a number in sorted order;
void in(vector<int> &ans, TreeNode *root)
{
    if (!root)
        return;
    in(ans, root->left);
    ans.push_back(root->val);
    in(ans, root->right);
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> ans;
    in(ans, root);
    return ans[k - 1];
}

// https://leetcode.com/problems/validate-binary-search-tree/
bool ans(TreeNode *root, long long low, long long high)
{
    if (!root)
        return true;
    if (root->val <= low || root->val >= high)
        return false;
    if (!root->left && !root->right)
        return true;
    return ans(root->left, low, root->val) && ans(root->right, root->val, high);
}
bool isValidBST(TreeNode *root)
{
    return ans(root, LLONG_MIN, LLONG_MAX);
}

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (p == root || q == root)
        return root;

    TreeNode *leftPart = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightPart = lowestCommonAncestor(root->right, p, q);

    if (leftPart == NULL && rightPart == NULL)
        return NULL;
    if (leftPart != NULL && rightPart == NULL)
        return leftPart;
    if (leftPart == NULL && rightPart != NULL)
        return rightPart;

    return root;
}
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
void insert(int value, TreeNode *root)
{
    while (root != NULL)
    {
        if (root->val < value)
        {
            if (root->right == NULL)
            {
                root->right = new TreeNode(value);
                break;
            }
            root = root->right;
        }
        else
        {
            if (root->left == NULL)
            {
                root->left = new TreeNode(value);
                break;
            }
            root = root->left;
        }
    }
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *root = new TreeNode(preorder[0]);
    int n = preorder.size();
    for (int i = 1; i < n; i++)
    {
        insert(preorder[i], root);
    }
    return root;
}

// https://leetcode.com/problems/binary-search-tree-iterator/
class BSTIterator {
    private: 
    stack<TreeNode*> s;
    void pushAll(TreeNode* root){
        while(root!=NULL){
            s.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};