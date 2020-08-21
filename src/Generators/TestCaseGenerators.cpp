#include "Generators/TestCaseGenerators.hpp"
#include "Generators/ArrayGenerators.hpp"

namespace pc {
namespace Generators {
namespace TestCaseGenerators {

void generate_sortings(const std::string& path, int count)
{
    for (int i = 0; i < count; ++i) {
        int len = (std::rand() % 10000 + 5);
        auto a = random_array(len);
        
    }
}

}
}
}