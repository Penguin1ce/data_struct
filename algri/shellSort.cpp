#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// 希尔排序函数
void shellSort(std::vector<int> &arr)
{
    int n = arr.size();
    // 初始步长设为数组长度的一半，每轮步长减半
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            // 将 temp 插入到当前步长的有序部分
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    std::vector<int> arr0 = {1, -1, 2, -2, 6};
    std::cout << "排序前数组: ";
    for (int i = 0; i < arr0.size(); i++)
        std::cout << arr0[i] << " ";
    std::cout << std::endl;
    shellSort(arr0);
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
    shellSort(arr);
    clock_t end = clock();

    double runtime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "希尔排序运行时间: " << runtime << " 秒" << std::endl;

    return 0;
}
