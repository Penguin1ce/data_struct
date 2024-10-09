#include <iostream>
using namespace std;

// 定义二叉树节点类
struct TreeNode
{
    int val;         // 节点的值
    TreeNode *left;  // 左子节点
    TreeNode *right; // 右子节点
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归函数：计算BST中所有节点值的和
int sumOfNodes(TreeNode *root)
{
    // 如果节点为空，返回 0
    if (root == nullptr)
    {
        return 0;
    }

    // 当前节点的值 + 左子树的和 + 右子树的和
    return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main()
{
    // 创建BST
    //          5
    //        /   \
    //       3     8
    //      / \   / \
    //     2   4 7   9

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    // 计算所有节点值的和
    int sum = sumOfNodes(root);
    cout << "Sum of all nodes: " << sum << endl;

    return 0;
}
