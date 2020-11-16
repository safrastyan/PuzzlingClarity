#include "Time/Time.hpp"
#include "algo/Sort.hpp"
#include "Generators/ArrayGenerators.hpp"

#include <algorithm>

using namespace pc::Time;
using namespace pc::Generators;
using namespace pc::algo;

int main()
{
    int n = 10000;
    auto arr = random_array(n);
        
    push();
    bubble_sort(arr);
    pop("bubble sort took");

    push();
    std::sort(arr.begin(), arr.end());
    pop("Std sort took");
    return 0; 
}