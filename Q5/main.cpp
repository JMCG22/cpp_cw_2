#include <iostream>

class MyClass
{
public:
    MyClass(int x);
    const int *get() const;
    int *get();

private:
    int x;
};

MyClass ::MyClass(int x) : x(x) {}

const int *MyClass ::get() const
{
    std ::cout << "I am const , x = " << x << std ::endl;
    return &x;
}

int *MyClass ::get()
{
    std ::cout << "I am not const , x = " << x << std ::endl;
    return &x;
}

int main()
{
    const MyClass a{1};
    MyClass b{2};
    MyClass *c = new MyClass{3};
    const MyClass *d = new MyClass{4};
    const MyClass &e{a};
    MyClass &f{b};
    a.get();
    b.get();
    c->get();
    d->get();
    e.get();
    f.get();
    delete d;
    delete c;
}
