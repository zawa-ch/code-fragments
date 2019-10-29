#include <iostream>

int main(int argc, char const *argv[])
{
    // gccではコンパイルできないが、clangではコンパイルできる
    int Cでは使えなかった日本語の識別子 = 10;
    std::string ハロー・ワールド = "Hello, world!";

    std::cout << Cでは使えなかった日本語の識別子 << std::endl;
    std::cout << ハロー・ワールド << std::endl;
    return 0;
}
