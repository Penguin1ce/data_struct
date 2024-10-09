#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// 定义Huffman树节点结构
struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq)
    {
        this->ch = ch;
        this->freq = freq;
        left = right = nullptr;
    }
};
// 比较函数，用于优先队列中按照频率从小到大排序
struct Compare
{
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};
// 递归生成Huffman编码
void generateHuffmanCodes(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;
    // 如果是叶节点，记录字符对应的Huffman编码
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }
    generateHuffmanCodes(root->left, str + "0", huffmanCode);
    generateHuffmanCodes(root->right, str + "1", huffmanCode);
}
// 释放Huffman树的内存
void freeHuffmanTree(Node *root)
{
    if (root == nullptr)
        return;
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    delete root;
}
// 构建Huffman树并生成编码
void buildHuffmanTree(string text)
{
    // 统计每个字符的频率
    unordered_map<char, int> freqMap;
    for (char ch : text)
    {
        freqMap[ch]++;
    }
    // 创建优先队列（最小堆），以频率为排序依据
    priority_queue<Node *, vector<Node *>, Compare> pq;
    // 创建叶节点并加入优先队列
    for (auto pair : freqMap)
    {
        pq.push(new Node(pair.first, pair.second));
    }
    // 直到队列中只剩下一个节点，构建Huffman树
    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        // 创建新节点，频率为两个子节点频率之和
        int sum = left->freq + right->freq;
        Node *newNode = new Node('\0', sum);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    // 获取Huffman树的根节点
    Node *root = pq.top();
    // 生成Huffman编码
    unordered_map<char, string> huffmanCode;
    generateHuffmanCodes(root, "", huffmanCode);
    // 输出每个字符的Huffman编码
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
    {
        cout << pair.first << ": " << pair.second << "\n";
    }
    // 编码输入字符串
    cout << "\nEncoded string: ";
    string encodedStr = "";
    for (char ch : text)
    {
        encodedStr += huffmanCode[ch];
    }
    cout << encodedStr << "\n";
    // 释放内存
    freeHuffmanTree(root);
}

int main()
{
    string text = "aaabbcddffecca";
    buildHuffmanTree(text);
    return 0;
}
