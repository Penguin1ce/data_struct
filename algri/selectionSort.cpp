#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// 选择排序函数
void selectionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // 交换找到的最小元素和当前位置的元素
        std::swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    std::vector<int> arr0 = {1, -1, 2, -2, 6};
    std::cout << "排序前数组: ";
    for (int i = 0; i < arr0.size(); i++)
        std::cout << arr0[i] << " ";
    std::cout << std::endl;
    selectionSort(arr0);
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
    selectionSort(arr);
    clock_t end = clock();

    double runtime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "选择排序运行时间: " << runtime << " 秒" << std::endl;

    return 0;
}
