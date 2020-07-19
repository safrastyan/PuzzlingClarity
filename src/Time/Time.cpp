#include "Time/Time.hpp"
#include "io/io.hpp"

#include <vector>
#include <chrono>

namespace {
static std::vector<std::chrono::high_resolution_clock::time_point> _times;

}
namespace pc {
namespace Time {

void push()
{
    _times.push_back(std::chrono::high_resolution_clock::now());
}

double pop(const std::string& str, std::ostream& out)
{
    if (_times.empty()) {
        io::write(str + " - This message has no time marked with it");
        return 0;
    }
    auto now = std::chrono::high_resolution_clock::now();
    
    auto before = _times.back();
    _times.pop_back();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(now - before);
    io::write(elapsed.count(), str, out);
    return elapsed.count();
}

}
}