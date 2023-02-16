#include <iostream>

void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    std::cout << "swap1: a: " << a << ", b: " << b << std ::endl;
}
void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    std::cout << "swap2: *a: " << *a << ", *b: " << *b << std ::endl;
}
void swap3(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    std::cout << "swap3: a: " << a << ", b: " << b << std ::endl;
}
int main()
{
    int a = 3;
    int b = 5;
    std::cout << "main: a: " << a << ", b: " << b << std ::endl;
    swap1(a, b);
    std::cout << "main: a: " << a << ", b: " << b << std ::endl;
    swap2(&a, &b);
    std::cout << "main: a: " << a << ", b: " << b << std ::endl;
    swap3(a, b);
    std::cout << "main: a: " << a << ", b: " << b << std ::endl;
}
