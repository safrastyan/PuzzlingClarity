#include "Generators/ArrayGenerators.hpp"
#include "algo/DivideAndConquer.hpp"
#include "io/io.hpp"
#include "Time/Time.hpp"

#include <iostream>

using namespace pc::Generators;
using namespace pc::io;
using namespace pc::algo;
using namespace pc;

int main()
{
    int n = 30000;

    auto arr = random_array(n);
    auto arr2 = arr;
    Time::push();
    auto res = significant_inversion_count_bad(arr);
    Time::pop("Bad algorithm, N^2");

    Time::push();
    res = significant_inversion_count(arr);
    Time::pop("NLogN algorithm");


    return 0;
}