#include <iostream>
#include <unordered_map>
int main()
{
    std::unordered_map<std::string, int> map;
    map.insert(std::pair("a", 1));
    map.insert(std::pair("b", 2));
    map.insert(std::pair("c", 3));
    for (auto &it : map)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
    int n;
    std::cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = i + j;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}