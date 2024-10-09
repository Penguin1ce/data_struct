#include <iostream>
#include <queue>
using namespace std;
// 定义二叉树节点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 中序遍历(左根右)
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
// 后序遍历(左右根)
void postorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}
// 前序遍历(根左右)
void preorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
// 层次遍历(按层次遍历)
void levelOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left != NULL)
            q.push(node->left); // 左子树入队
        if (node->right != NULL)
            q.push(node->right); // 右子树入队
    }
}
void search(TreeNode *root, int K)
{
    if (root == NULL)
        return;
    if (root->val == K)
    {
        cout << "Find " << K << endl;
        return;
    }
    search(root->left, K);
    search(root->right, K);
}
int main()
{
    // 创建一个简单的二叉树
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    search(root, 3);
    cout << "中序遍历结果: ";
    inorderTraversal(root);
    cout << endl;
    cout << "后序遍历结果: ";
    postorderTraversal(root);
    cout << endl;
    cout << "前序遍历结果: ";
    preorderTraversal(root);
    cout << endl;
    cout << "层次遍历结果: ";
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}
