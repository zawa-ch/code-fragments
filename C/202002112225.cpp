#include <iostream>
#include <utility>

class AbstractClass
{
public:
    virtual void foo() const = 0; // 純粋仮想関数の宣言(このクラスはabstractとなる)
};

class SubClass : virtual public AbstractClass
{
public:
    void foo() const { std::cout << "do something" << std::endl; } // AbstractClass::fooの実装
};

class AbstractHolder
{
public:
    virtual AbstractClass&& get() const = 0;
};

class SubHolder1
{
public:
    AbstractClass&& get() const { return SubClass(); } // 転送参照ではないため、オブジェクトの生存期間はこの関数内のみ
};

class SubHolder2
{
public:
    AbstractClass&& get() const { return std::forward<AbstractClass>(SubClass()); } // 転送参照、オブジェクトの生存期間が延長される
};

int main()
{
    AbstractClass&& rref1 = SubClass(); // OK、オブジェクトはmain関数内で生存する
    rref1.foo();

    SubHolder1 holder1 = SubHolder1();
    AbstractClass&& rref2 = holder1.get(); // エラー、破棄されたオブジェクトへの参照
    rref2.foo();

    SubHolder2 holder2 = SubHolder2();
    AbstractClass&& rref3 = holder2.get(); // OK、std::forwardを使用して転送されるため、生存期間が延長される
    rref3.foo();

    return 0;
}
