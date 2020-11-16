#include "Time/Time.hpp"
#include "algo/Sort.hpp"
#include "Generators/ArrayGenerators.hpp"

#include <algorithm>

using namespace pc::Time;
using namespace pc::Generators;
using namespace pc::algo;

int main()
{
    int n = 1000000;
    int max_elem = 1000;
    auto arr = random_array(n, 0, max_elem);
    
    push();
    bucket_sort(arr, max_elem);
    pop("bucket sort took");

    push();
    std::sort(arr.begin(), arr.end());
    pop("Std sort took");
    return 0; 
}