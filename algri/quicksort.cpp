#include <iostream>
using namespace std;
int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= pivot)
            --high;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot)
            ++low;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(arr, low, high);
        QuickSort(arr, low, pivotpos - 1);
        QuickSort(arr, pivotpos + 1, high);
    }
}
int main()
{
    int a[] = {49, 38, 65, 97, 76, 13, 27, 48};
    QuickSort(a, 0, 7);
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}