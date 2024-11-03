#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void insertionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // 将arr[i]插入到已排序部分的正确位置
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    std::vector<int> arr0 = {1, -1, 2, -2, 6};
    std::cout << "排序前数组: ";
    for (int i = 0; i < arr0.size(); i++)
        std::cout << arr0[i] << " ";
    std::cout << std::endl;
    insertionSort(arr0);
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
    insertionSort(arr);
    clock_t end = clock();

    double runtime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "插入排序运行时间: " << runtime << " 秒" << std::endl;
    return 0;
}
