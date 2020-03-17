#include "algo/DateAndTime.hpp"

namespace pc {
namespace algo {

bool is_leap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

}
}
