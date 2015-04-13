#include <iostream>

int main()
{
    int sum, value;
    sum = 0;

    while (std::cin >> value)
        if (value <= 0)
            ++sum;

    std::cout << "sum of negative numbers is "
          << sum << std::endl;

    return 0;
}
