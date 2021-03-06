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

/// for a ahcarater matrix no spaces
template<>
inline void write(const std::vector<std::vector<char>>& obj, const std::string& str, std::ostream& out, Options op)
{
    for (int i = 0; i < obj.size(); ++i) {
        if (str.size() != 0) {    
            out << str << " " << i <<std::endl;
        }
        for (auto y: obj[i]) {
            out << y;
        }
        if (op.add_new_line) {
            out << std::endl;   
        }    
    }
}


template<typename T>
T read_one(std::istream& in)
{
    T x;
    in >> x;
    return x;
}

template<typename T>
inline std::vector<T> read_array(std::istream& in)
{
    int n;
    in >> n;
    std::vector<T> a(n);
    for (int i = 0; i < n; ++i) {
        in >> a[i];
    }
    return a;
}

template<typename T>
std::vector<T> read_array_u(std::istream& in)
{
    std::vector<T> a;
    T x;
    while (in >> x) {
        a.push_back(x);
    }
    return a;
}

template<typename T, typename U>
inline std::vector<std::pair<T, U>> read_array(std::istream& in)
{
    int n;
    in >> n;
    std::vector<std::pair<T, U>> a(n);
    for (int i = 0; i < n; ++i) {
        in >> a[i].first >> a[i].second;
    }

    return a;
}

}
}

