#include <vector>

namespace pc {
namespace io {

/// For arrays the string will be printed before the array
template<>
inline void write(const std::vector<int>& obj, const std::string& str, std::ostream& out, Options op)
{
    if (!str.empty()) {
        out << str << std::endl;
    }
    for (auto x: obj) {
        out << x << " ";
    }
    if (op.add_new_line) {
        out << std::endl;
    }
}

/// for the matrix meta text will be printed before each row with index
template<>
inline void write(const std::vector<std::vector<int>>& obj, const std::string& str, std::ostream& out, Options op)
{
    for (int i = 0; i < obj.size(); ++i) {
        if (str.size() != 0) {    
            out << str << " " << i <<std::endl;
        }
        for (auto y: obj[i]) {
            out << y << " ";
        }
        if (op.add_new_line) {
            out << std::endl;   
        }    
    }
}

}
}

