void leftBoundary(Node *root, vector<int>&result)
{
if(root == NULL) return ;
if(root->left == NULL && root->right == NULL) return ;

result.push_back(root->data) ;

if(root->left != NULL) {
leftBoundary(root->left, result) ;
}
else {
leftBoundary(root->right, result) ;
}
}

void leavesBoundary(Node *root, vector<int>&result)
{
if(root == NULL) return ;
if(root->left == NULL && root->right == NULL) {
result.push_back(root->data) ;
return ;
}
leavesBoundary(root->left, result) ;
leavesBoundary(root->right, result) ;
}

void rightBoundary(Node *root, vector<int>&result)
{
if(root == NULL) return ;
if(root->left == NULL && root->right == NULL) return ;


if(root->right != NULL) {
rightBoundary(root->right, result) ;
}
else {
rightBoundary(root->left, result) ;
}

result.push_back(root->data) ;
}

vector <int> boundary(Node *root)
{
vector<int>result ;
result.push_back(root->data) ;

if(root->left == NULL && root->right == NULL)
return result ;

// Left Boundary
leftBoundary(root->left, result) ;


// Leaves Boundary
leavesBoundary(root, result) ;

// Right Boundary
rightBoundary(root->right, result) ;
}