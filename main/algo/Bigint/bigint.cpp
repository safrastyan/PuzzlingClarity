#include "algo/BigInt.hpp"
#include "io/io.hpp"
#include "Time/Time.hpp"

#include <iostream>

using namespace pc::io;
using namespace pc::algo;
using namespace pc;

int main()
{
    // auto a = read_one<std::string>(std::cin);
    // auto b = read_one<std::string>(std::cin);


    auto k = BigInt(426242631518)- BigInt(6) * BigInt(61299103997);

    std::cout << k << std::endl;

    return 0;
}