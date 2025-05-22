#include <iostream>

#include "long_number.hpp"

int main()
{
    naa::LongNumber a {"-200533453453540"};
    naa::LongNumber b {"123"};
    std:: cout << (a > b) << std::endl;
    return 0;
}
