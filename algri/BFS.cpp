#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 图的邻接表表示
class Graph
{
    int V;                   // 顶点个数
    vector<vector<int>> adj; // 邻接表

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

    // 广度优先遍历
    void BFS(int start)
    {
        vector<bool> visited(V, false); // 初始化所有节点为未访问状态
        queue<int> q;                   // 定义一个队列

        // 标记起始节点为已访问并入队
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            // 从队列中取出一个节点
            int node = q.front();
            q.pop();
            cout << node << " "; // 输出当前节点

            // 访问所有相邻的未访问节点
            for (int i : adj[node])
            {
                if (!visited[i])
                {
                    visited[i] = true; // 标记为已访问
                    q.push(i);         // 将节点入队
                }
            }
        }
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

    cout << "从节点 0 开始的广度优先遍历: ";
    g.BFS(0); // 从节点 0 开始广度优先遍历

    return 0;
}
