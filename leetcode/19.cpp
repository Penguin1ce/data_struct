#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        v.push_back(a[i]);
    }
    cout << v[-2] << endl;
    return 0;
}