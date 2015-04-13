#include <iostream>

int main()
{
    int v1, v2;

    std::cout << "Please input two numbers" << std::endl;
    std::cin >> v1 >> v2;

    if (v1 >= v2)
        std::cout << "The big number is " << v1 << std::endl;
    else
        std::cout << "The big number is " << v2 << std::endl;

    return 0;
}
