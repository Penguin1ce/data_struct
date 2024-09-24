#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;     // 用于存储栈元素的数组
    int topIndex; // 栈顶索引
    int capacity; // 栈的容量（数组大小）
    // 扩容函数，当栈满时扩展数组
    void resize()
    {
        int *newArr = new int[capacity * 2]; // 创建一个容量为当前的两倍的新数组
        for (int i = 0; i < capacity; i++)
        {
            newArr[i] = arr[i]; // 将旧数组的元素复制到新数组
        }
        delete[] arr;  // 释放旧数组的内存
        arr = newArr;  // 更新数组指针为新数组
        capacity *= 2; // 更新容量
    }
public:
    // 构造函数
    Stack(int size = 10)
    {
        arr = new int[size]; // 初始化数组
        topIndex = -1;       // 栈顶初始化为 -1，表示栈为空
        capacity = size;     // 设置初始容量
    }
    // 析构函数，用于释放动态分配的内存
    ~Stack()
    {
        delete[] arr;
    }
    // 检查栈是否为空
    bool isEmpty()
    {
        return topIndex == -1;
    }
    // 获取栈中元素的数量
    int size()
    {
        return topIndex + 1;
    }
    // 获取栈的容量
    int getCapacity()
    {
        return capacity;
    }
    // 入栈操作
    void push(int x)
    {
        if (topIndex == capacity - 1)
        {
            resize(); // 如果栈满了，进行扩容
        }
        arr[++topIndex] = x; // 将元素压入栈顶
    }
    // 出栈操作
    void pop()
    {
        if (isEmpty())
        {
            cout << "栈为空，无法执行 pop 操作" << endl;
        }
        else
        {
            topIndex--; // 将栈顶索引减少
        }
    }
    // 查看栈顶元素
    int top()
    {
        if (isEmpty())
        {
            cout << "栈为空" << endl;
            return -1; // 返回一个无效值
        }
        return arr[topIndex];
    }
};

int main()
{
    Stack s; // 创建一个默认大小为 10 的栈
    // 入栈操作
    s.push(1);
    s.push(2);
    s.push(3);
    // 显示栈顶元素
    cout << "栈顶元素: " << s.top() << endl; // 输出 3
    // 出栈操作
    s.pop();
    // 再次显示栈顶元素
    cout << "栈顶元素: " << s.top() << endl; // 输出 2
    // 显示栈是否为空
    cout << (s.isEmpty() ? "栈为空" : "栈不为空") << endl;
    // 显示栈中元素数量
    cout << "栈中元素数量: " << s.size() << endl; // 输出 2
    return 0;
}