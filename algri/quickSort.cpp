#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// 分区函数，以最左边的元素作为基准
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // 选择最左边的元素作为基准
    int i = low + 1;      // 从基准的下一个元素开始
    int j = high;

    while (true)
    {
        // 从左向右找到第一个大于基准的元素
        while (i <= j && arr[i] <= pivot)
        {
            i++;
        }
        // 从右向左找到第一个小于基准的元素
        while (i <= j && arr[j] >= pivot)
        {
            j--;
        }
        // 如果i和j重叠，退出循环
        if (i >= j)
            break;

        // 交换arr[i]和arr[j]
        std::swap(arr[i], arr[j]);
    }
    // 将基准放到正确位置
    std::swap(arr[low], arr[j]);
    return j;
}

// 快速排序函数
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // 获取分区索引

        quickSort(arr, low, pi - 1);  // 递归排序左侧
        quickSort(arr, pi + 1, high); // 递归排序右侧
    }
}

int main()
{
    std::vector<int> arr0 = {1, -1, 2, -2, 6};
    std::cout << "排序前数组: ";
    for (int i = 0; i < arr0.size(); i++)
        std::cout << arr0[i] << " ";
    std::cout << std::endl;
    quickSort(arr0, 0, arr0.size() - 1);
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
    quickSort(arr, 0, arr.size() - 1);
    clock_t end = clock();

    double runtime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "快速排序运行时间: " << runtime << " 秒" << std::endl;

    return 0;
}
