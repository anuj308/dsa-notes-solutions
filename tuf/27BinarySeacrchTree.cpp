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
int findMax(Node *root) {
        int max = INT_MIN;
        while(root!=NULL){
            max=root->data;
            root=root->right;
        }
        return max;
        
    }

    int findMin(Node *root) {
        
       int min = INT_MAX;
        while(root!=NULL){
            min=root->data;
            root=root->left;
        }
        return min;
    }

// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
    int findCeil(Node* root, int input) {
    // Your code here
    int ans = -1;
    while(root!=NULL){
        if(root->data>=input){
            ans=root->data;
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return ans;
}
// https://www.geeksforgeeks.org/problems/floor-in-bst/1
 int floor(Node* root, int x) {
        int ans = -1;
        while(root!=NULL){
            if(root->data<=x){
                ans = root->data;
                root= root->right;
            }else{
                root = root->left;
            }
        }
        return ans;
    }