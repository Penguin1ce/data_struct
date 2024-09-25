// 现代C++新特性
#include <iostream>
#include <vector>

auto sum(float a, float b) // 函数返回值后置
{
    return a + b;
}
int main()
{
    auto x = 1; // auto关键字可以自动推断变量的类型
    auto y = 2.0;
    int i[5];
    auto m = i; // m的类型是int*
    std::cout << sum(3.5, y) << std::endl;
    std::vector<int> vec = {1, 2, 3, 4};
    for(auto it = vec.begin(); it != vec.end(); it++) 
    {
        std::cout << *it << " ";  // 输出 1 2 3 4
    }

}