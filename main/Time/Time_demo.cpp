#include "Time/Time.hpp"
#include "Generators/ArrayGenerators.hpp"
int main()
{
    pc::Time::push();
    pc::Time::pop("This should be almost instant");
    pc::Time::push();
    auto r = pc::Generators::array_from_1_to_n(10000000);
    pc::Time::pop("This Should be little slower");
    return 0;
}