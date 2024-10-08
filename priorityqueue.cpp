#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // 定义优先队列，默认是最大堆
    priority_queue<int> maxHeap;
    // 插入元素
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(40);
    maxHeap.push(15);

    // 输出并移除堆顶元素
    while (!maxHeap.empty()) {
        cout << "Top element: " << maxHeap.top() << endl;  // 输出当前堆顶元素
        maxHeap.pop();  // 移除堆顶元素
    }

    return 0;
}
