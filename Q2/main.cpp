#include <iostream>

int main()
{
    int i = 5;
    int j = i++;
    int k = ++i;
    std::cout << "i: " << i << std ::endl;
    std::cout << "j: " << j << std ::endl;
    std::cout << "k: " << k << std ::endl;
}
