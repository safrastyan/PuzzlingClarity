#pragma once

#include <functional>
#include <vector>

namespace pc {
namespace algo {


template<typename T>
class SegmentTree
{
public:
    using Func = std::function<T(const T&, const T&)>;
    SegmentTree(const std::vector<int>& data, Func f, const T& bad_value);
    T query(int left, int right);

    bool update(const T& val, int pos); ///TODO implement this
    
private:
    void build(const std::vector<T>& data);


    void build_rec(const std::vector<T>& data, int v, int left, int right);
    T query_rec(int v, int tleft, int tright, int left, int right);
private:
    std::vector<int> m_tree;
    std::vector<T> m_data;
    T m_bad_value;
    Func m_f;
    int m_original_size;
};


/// specific cases for Min and Max Segment trees for easy access
template<typename T>
SegmentTree<T> range_minimum_query(const std::vector<T>&);

template<typename T>
SegmentTree<T> range_maximum_query(const std::vector<T>&);

}
}

#include "SegmentTree_impl.hpp"