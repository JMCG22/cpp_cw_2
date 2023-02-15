#include <iostream >

class MyClass
{
public:
    MyClass(int x);
    const int *get() const;
    int *get();

private:
    int x;
};
// constructor assigning x to x
MyClass ::MyClass(int x) : x(x) {}

// get, cant modify class, returns const int pointer
const int *MyClass ::get() const
{
    std ::cout << "I am const , x = " << x << std ::endl;
    return &x;
}

// get, can modify class, returns int pointer
int *MyClass ::get()
{
    std ::cout << "I am not const , x = " << x << std ::endl;
    return &x;
}

int main()
{
    const MyClass a{1};
    // const, a=1

    MyClass b{2};
    // b=2

    // pointer to c =3
    MyClass *c = new MyClass{3};

    // pointer to d =4, const
    const MyClass *d = new MyClass{4};

    // e =1, const reference
    const MyClass &e{a};

    // f =2, reference
    MyClass &f{b};

    // i am  const
    a.get();

    // i am not const
    b.get();

    // not const
    c->get();

    // const
    d->get();

    // const
    e.get();

    // not const as f is not a cost ref
    f.get();

    // doesnt print bc no destructor
    delete d;
    delete c;
}
