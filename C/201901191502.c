#include <stdio.h>
int main(int argc, char const *argv[])
{
    for(int i = 1; i <= 100; i++)
        printf("%d %s%s\r\n", i, i%3?"":"Fizz", i%5?"":"Buzz");
    return 0;
}
