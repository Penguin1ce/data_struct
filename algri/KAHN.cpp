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

    // 拓扑排序
    void topologicalSort()
    {
        vector<int> inDegree(V, 0); // 存储每个节点的入度

        // 计算每个节点的入度
        for (int i = 0; i < V; ++i)
        {
            for (int j : adj[i])
            {
                inDegree[j]++;
            }
        }

        // 创建一个队列，将所有入度为 0 的节点入队
        queue<int> q;
        for (int i = 0; i < V; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // 拓扑排序结果
        vector<int> topOrder;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topOrder.push_back(node);

            // 遍历当前节点的所有邻接节点，入度减 1
            for (int i : adj[node])
            {
                if (--inDegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        // 检查是否存在环
        if (topOrder.size() != V)
        {
            cout << "图中存在环，无法进行拓扑排序。" << endl;
            return;
        }

        // 输出拓扑排序结果
        cout << "拓扑排序结果: ";
        for (int i : topOrder)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    // 创建一个图并添加边
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "拓扑排序: ";
    g.topologicalSort(); // 执行拓扑排序

    return 0;
}
