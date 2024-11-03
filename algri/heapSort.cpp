#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// 堆化函数，将子树调整为最大堆
void heapify(std::vector<int> &arr, int n, int i)
{
    int largest = i;       // 将根节点设为最大值
    int left = 2 * i + 1;  // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点大于根节点
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // 如果右子节点大于当前最大节点
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // 如果最大值不是根节点，交换并继续堆化
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heapSort(std::vector<int> &arr)
{
    int n = arr.size();

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // 一个一个从堆顶取出元素并调整堆
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]); // 将当前根移到数组末尾
        heapify(arr, i, 0);        // 重新调整堆
    }
}

int main()
{
    std::vector<int> arr0 = {1, -1, 2, -2, 6};
    std::cout << "排序前数组: ";
    for (int i = 0; i < arr0.size(); i++)
        std::cout << arr0[i] << " ";
    std::cout << std::endl;
    heapSort(arr0);
    std::cout << "排序后数组: ";
    for (int i = 0; i < arr0.size(); i++)
        std::cout << arr0[i] << " ";
    std::cout << std::endl;

    // 初始化随机数种子
    std::srand(static_cast<unsigned>(std::time(0)));

    // 生成随机数组
    std::vector<int> arr(1000);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = std::rand() % 10000; // 随机数范围 0 到 9999
    }

    // 测量运行时间
    clock_t start = clock();
    heapSort(arr);
    clock_t end = clock();

    double runtime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "堆排序运行时间: " << runtime << " 秒" << std::endl;

    return 0;
}
