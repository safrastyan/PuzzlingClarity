#pragma once

namespace pc {
namespace algo {
    
template<typename T>
inline SegmentTree<T>::SegmentTree(const std::vector<int>& data, Func f, const T& bad_value): m_f(f)
                                                                                            , m_bad_value(bad_value)
                                                                                            , m_original_size(data.size())
{
    build(data);
}

template<typename T>
inline T SegmentTree<T>::query(int left, int right)
{
    return query_rec(1, 0, m_original_size - 1, left, right);
}

template<typename T>
inline void SegmentTree<T>::build(const std::vector<T>& data)
{
    m_tree = std::vector<T>(data.size() * 4);
    build_rec(data, 1, 0, m_original_size - 1);
}

template<typename T>
inline void SegmentTree<T>::build_rec(const std::vector<T>& data, int v, int left, int right)
{
    if (left == right) {
        m_tree[v] = data[left];
        return;
    }
    int mid = (left + right) / 2;
    build_rec(data, v * 2, left, mid);
    build_rec(data, v * 2 + 1, mid + 1, right);
    m_tree[v] = m_f(m_tree[v * 2], m_tree[v * 2 + 1]);
}

template<typename T>
inline T SegmentTree<T>::query_rec(int v, int tleft, int tright, int left, int right)
{
    if (left > right) {
        return m_bad_value;
    }
    if (left == tleft && right == tright) {
        return m_tree[v];
    }
    int mid = (tleft + tright) / 2;
    return m_f(query_rec(v * 2, tleft, mid, left, std::min(right, mid)), query_rec(v * 2 + 1, mid + 1, tright, std::max(left, mid + 1), right));
}

template<typename T>
inline SegmentTree<T> range_minimum_query(const std::vector<T>& data)
{
    return SegmentTree<T>(data, [](const T& a, const T& b){return a < b ? a : b;}, std::numeric_limits<T>::max());   
}

template<typename T>
SegmentTree<T> range_maximum_query(const std::vector<T>& data)
{
    return SegmentTree<T>(data, [](const T& a, const T&b){return a > b ? a : b;}, std::numeric_limits<T>::min());
}

}
}
