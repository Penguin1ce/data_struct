#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// 合并两个子数组的函数
void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    std::vector<int> leftArr(n1), rightArr(n2);

    // 将数据复制到临时数组
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // 合并两个子数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // 复制剩余元素
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// 归并排序函数
void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // 递归排序两部分
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并已排序的部分
        merge(arr, left, mid, right);
    }
}

int main()
{
    std::vector<int> arr0 = {1, -1, 2, -2, 6};
    std::cout << "排序前数组: ";
    for (int i = 0; i < arr0.size(); i++)
        std::cout << arr0[i] << " ";
    std::cout << std::endl;
    mergeSort(arr0, 0, arr0.size() - 1);
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
    mergeSort(arr, 0, arr.size() - 1);
    clock_t end = clock();

    double runtime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "归并排序运行时间: " << runtime << " 秒" << std::endl;

    return 0;
}
