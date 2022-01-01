#pragma once

namespace pc {
namespace ds {


template<typename T>
inline size_t Stack<T>::size() const noexcept
{
    return m_data.size();
}

template<typename T>
inline bool Stack<T>::empty() const noexcept
{
    return m_data.size() == 0;
}

template<typename T>
inline T Stack<T>::top() const
{
    return m_data[m_data.size() - 1];
}

template<typename T>
void Stack<T>::push(const T& val)
{
    m_data.push_back(val);
}

template<typename T>
void Stack<T>::pop()
{
    m_data.pop_back();
}


}
}
