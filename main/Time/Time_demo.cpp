#include "Time/Time.hpp"
#include "Generators/ArrayGenerators.hpp"
int main()
{
    pc::Time::push();
    pc::Time::pop("This should be almost instant");
    pc::Time::push();
    auto r = pc::Generators::ArrayFrom1toN(10000000);
    pc::Time::pop("This Should be little slower");
    return 0;
}