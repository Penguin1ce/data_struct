#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// 冒泡排序函数
void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false; // 用于优化，检测是否发生交换
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // 如果没有发生交换，数组已经有序
        if (!swapped)
            break;
    }
}

int main()
{
    std::vector<int> arr0 = {1, -1, 2, -2, 6};
    std::cout << "排序前数组: ";
    for (int i = 0; i < arr0.size(); i++)
        std::cout << arr0[i] << " ";
    std::cout << std::endl;
    bubbleSort(arr0);
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
    bubbleSort(arr);
    clock_t end = clock();

    double runtime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "冒泡排序运行时间: " << runtime << " 秒" << std::endl;

    return 0;
}
