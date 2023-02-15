#include <iostream >
#include <chrono>
#include <thread>


class MyClass
{
public:
    MyClass(int x) : x(x)
    {
        std ::cout << " constructor called , x = " << this->x << std ::endl;
    }
    MyClass(const MyClass &other) : x(other.x)
    {
        std ::cout << "copy constructor called , x = " << x << std ::endl;
    }
    MyClass &operator=(const MyClass &other)
    {
        std ::cout << " assignment operator called , x was " << x << " and became " << other.x << std ::endl;
        x = other.x;
        return *this;
    }
    ~MyClass()
    {
        std::cout << " destructor called , x = " << this->x << std::endl;
    }
    void print()
    {
        std ::cout << " x = " << this->x << std ::endl;
    }

private:
    int x;
};

void test(int n)
{
    MyClass a(n);
    a.print();

    return;
}
int main()
{
    MyClass a{3};
    MyClass b(5);
    MyClass c{a};
    c = b;
    a = b;

    a.print();
    b.print();
    c.print();

    MyClass *d = new MyClass(7);
    d->print();
    delete d;
    test(100);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}