#include <iostream>

class AbstractClass
{
public:
    virtual void foo() const = 0;
};

class SubClass : virtual public AbstractClass
{
public:
    void foo() const { std::cout << "do something" << std::endl; }
};

int main()
{
    AbstractClass&& rref = SubClass();
    rref.foo();
    return 0;
}
