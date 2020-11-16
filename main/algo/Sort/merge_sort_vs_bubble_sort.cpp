#include "Time/Time.hpp"
#include "algo/Sort.hpp"
#include "Generators/ArrayGenerators.hpp"
#include "io/io.hpp"

using namespace pc::io;
using namespace pc::Time;
using namespace pc::Generators;
using namespace pc::algo;

int main()
{
    int n = 1000;
    auto arr = random_array(n);
        
    push();
    bubble_sort(arr);
    pop("bubble sort took");

    push();
    merge_sort(arr);
    pop("merge sort took");


    n = 20;
    arr = random_array(n, 0, 1000);
    auto res = merge_sort(arr);
    write(res, "After mergesorting the shit");
    return 0; 
}