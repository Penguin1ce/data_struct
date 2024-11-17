#include <iostream>
#include <vector>
using namespace std;

// 图的邻接表表示
class Graph
{
    int V;                   // 顶点个数
    vector<vector<int>> adj; // 邻接表

    // 深度优先遍历的递归函数
    void DFSUtil(int v, vector<bool> &visited)
    {
        // 标记当前节点为已访问
        visited[v] = true;
        cout << v << " "; // 输出当前节点

        // 递归访问所有相邻的未访问节点
        for (int i : adj[v])
        {
            if (!visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

public:
    // 构造函数
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    // 添加边
    void addEdge(int v, int w)
    {
        adj[v].push_back(w); // 将 w 添加到 v 的邻接表中
    }

    // 深度优先遍历
    void DFS(int start)
    {
        vector<bool> visited(V, false); // 初始化所有节点为未访问状态
        DFSUtil(start, visited);        // 从起始节点开始 DFS
    }
};

int main()
{
    // 创建一个图并添加边
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "从节点 0 开始的深度优先遍历: ";
    g.DFS(0); // 从节点 0 开始深度优先遍历

    return 0;
}
