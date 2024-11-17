#include <iostream>
using namespace std;

// 节点结构
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 插入节点
TreeNode *insert(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

// 查找节点
bool search(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }
    if (value == root->value)
    {
        return true;
    }
    else if (value < root->value)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

// 中序遍历
void inorderTraversal(TreeNode *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

// 删除节点
TreeNode *deleteNode(TreeNode *root, int value)
{
    if (root == nullptr)
        return root;
    if (value < root->value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        TreeNode *temp = root->right;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

int main()
{
    TreeNode *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "中序遍历: ";
    inorderTraversal(root);
    cout << endl;

    cout << "查找 40: " << (search(root, 40) ? "找到" : "未找到") << endl;

    root = deleteNode(root, 50);
    cout << "删除 50 后的中序遍历: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
