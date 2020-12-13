#include <random>

namespace pc {
namespace Generators {
    
int random_number(int left, int right)
{    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(left, right);

    return distr(gen);
}

}
}
