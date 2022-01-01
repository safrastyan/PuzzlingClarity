#pragma once

namespace pc {
namespace ds {

template<typename T>
class Vector
{
public:
    Vector();

    Vector(const Vector<T>&);

    /// Vector with n defalt elements
    Vector(int n);

    /// N elements with default value
    Vector(int n, const T& def);


    size_t size() const noexcept;
    bool empty() const noexcept;
    size_t capacity() const noexcept;
    T& back();
    T operator[](int) const;
    T& operator[](int);

    void push_back(const T&);
    void pop_back();

    ~Vector();
private:

    void normalize_if_necessary();

    /// allocate new memory and copy the data based on the value of capacity
    void reallocate();

    static constexpr int default_capacity = 10;
    static constexpr float capacity_increase_coef = 2.0;
    static constexpr int capacity_size_diff_normalize_coef = 4; ///if the size is 4 times less then the cap, decrease the cap twice
    static constexpr int should_care_threshold = 100; /// if the elemes are less then 100 don't care about memory

    size_t m_size;
    size_t m_capacity;
    T* m_data;
};

}
}

#include "ds/Vector_impl.hpp"

