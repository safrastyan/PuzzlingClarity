#include <io/io.hpp>

int main()
{
    pc::io::write("Vector");
    pc::io::write(std::vector<int>{1, 2, 3}, "Support");
    pc::io::write("Now trying matrix");
    pc::io::write(std::vector<std::vector<int>>{{1, 2, 3}, {4, 5, 6}, {10, 10, 10}}, "This is Row");
    return 0;
}