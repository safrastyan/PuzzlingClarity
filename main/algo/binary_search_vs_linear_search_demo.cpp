#include "io/io.hpp"
#include "Time/Time.hpp"
#include "Generators/ArrayGenerators.hpp"
#include "algo/Searches.hpp"

#include <algorithm>

using namespace pc::algo;
using namespace pc::Time;

int main()
{
    auto a = pc::Generators::ArrayFrom1toN(1000000, 100);
    push();
    for (int i = 1000000; i >= 1000000 - 1000; --i) {
        auto f = std::find(a.begin(), a.end(), i * 100);
    }
    pop("1000 quesrios on million array linearly took");

    push();
    for (int i = 1000000; i >= 1000000 - 1000; --i) {
        auto f = binary_search(a, i * 100);
    }
    pop("1000 quesrios on million array with binary search took");
    return 0;

}