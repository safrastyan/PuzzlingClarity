#include "algo/fibonacci.hpp"
#include "io/io.hpp"
#include "Time/Time.hpp"

using namespace pc::io;
int main()
{
    int n = 30;
    pc::Time::push();
    pc::algo::fib_dp(30);
    pc::Time::pop("Dp Fibonacci for 30 took");
    
    pc::Time::push();
    pc::algo::fib_rec(30);
    pc::Time::pop("Recursive Fibonacci for 30 took");
    
    return 0;
}