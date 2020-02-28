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
    int a;
    void foo() const { std::cout << "do something " << a << std::endl; } // AbstractClass::fooの実装
};

class AbstractHolder
{
public:
    virtual AbstractClass&& get() const = 0;
};

class SubHolder1
{
public:
    SubClass&& get() const { return SubClass(); } // オブジェクトの生存期間はこの関数内のみ
};

class SubHolder2
{
public:
    SubClass&& get() const { return std::forward<SubClass>(SubClass()); } // 転送されるように思えたが、実際には返り値が受け取られる前にオブジェクトは破棄される(記憶域は破棄されない、おそらく処理系定義)?
};

int main()
{
    AbstractClass&& rref1 = SubClass(); // OK、オブジェクトはmain関数内で生存する
    rref1.foo();

    SubHolder1 holder1 = SubHolder1();
    SubClass&& rref2 = holder1.get(); // 破棄されたオブジェクトへの参照
    //rref2.a = 2;
    //rref2.foo();

    SubHolder2 holder2 = SubHolder2();
    SubClass&& rref3 = holder2.get();
    rref3.a = 3;
    rref3.foo(); // 3ではなく何らかの値が表示される

    return 0;
}
