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

class AbstractHolder
{
public:
    virtual AbstractClass&& get() const = 0;
};

class SubHolder
{
public:
    AbstractClass&& get() const { return SubClass(); } // オブジェクトの生存期間はこの関数内のみ
};

int main()
{
    AbstractClass&& rref1 = SubClass(); // OK、オブジェクトはmain関数内で生存する
    rref1.foo();

    SubHolder holder = SubHolder();
    AbstractClass&& rref2 = holder.get(); // エラー、破棄されたオブジェクトへの参照
    rref2.foo();

    return 0;
}
