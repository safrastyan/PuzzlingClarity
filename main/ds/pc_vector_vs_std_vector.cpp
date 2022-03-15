#include "io/io.hpp"
#include "Time/Time.hpp"
#include "ds/Vector.hpp"

#include <vector>

using namespace pc::ds;
using namespace pc::Time;

int main()
{
    int n = 100000000;
    

    Vector<int> v;
    push();
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
    }

    pop("100000000 many pushes in puzzling vector took");

    std::vector<int> sv;
    push();
    for (int i = 0; i < n; ++i) {
        sv.push_back(i);
    }

    pop("100000000 many pushes in std vector took");
    return 0;
    
}