#pragma once

#include "ds/Vector.hpp"

namespace pc {
namespace ds {

template<typename T>
class Stack
{
public:
    Stack() = default;

    void push(const T&);
    void pop();
    T top() const;
    size_t size() const noexcept;
    bool empty() const noexcept;
    
    ~Stack() = default;
private:
    Vector<T> m_data;
};

}
}

#include "ds/Stack_impl.hpp"
