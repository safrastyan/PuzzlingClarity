#pragma once

namespace pc {
namespace ds {

template<typename T>
inline Vector<T>::Vector(): m_size(0)
                          , m_capacity(default_capacity)  
                          , m_data(new T[m_capacity])
{}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& v): m_size(v.size())
                                            , m_capacity(v.capacity())
                                            , m_data(new T[v.capacity()])
{
    for (int i = 0; i < v.size(); ++i) {
        m_data[i] = v[i];
    }
}

template<typename T>
inline Vector<T>::Vector(int n): m_size(n)
                               , m_capacity(n)
                               , m_data(new T[m_capacity])
{} 

    /// N elements with default value
template<typename T>
inline Vector<T>::Vector(int n, const T& def): m_size(n)
                                             , m_capacity(n)
                                             , m_data(new T[m_capacity]) 
{
    for (int i = 0; i < size(); ++i) {
        m_data[i] = def;
    }
}  

template<typename T>
inline size_t Vector<T>::size() const noexcept
{
    return m_size;
}

template<typename T>
inline bool Vector<T>::empty() const noexcept
{
    return m_size == 0;
}
    
    
template<typename T>
inline size_t Vector<T>::capacity() const noexcept
{
    return m_capacity;
}

template<typename T>
inline T& Vector<T>::back()
{
    return m_data[m_size - 1];
}

template<typename T>
T Vector<T>::operator[](int i) const
{
    return m_data[i];
}

template<typename T>
T& Vector<T>::operator[](int i)
{
    return m_data[i];
}


template<typename T>
void Vector<T>::push_back(const T& val)
{
    m_data[m_size] = val;
    ++m_size;
    normalize_if_necessary();
}

template<typename T>
void Vector<T>::pop_back()
{
    if (m_size == 0) {
        return;
    }
    --m_size;
    normalize_if_necessary();
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

template<typename T>
void Vector<T>::normalize_if_necessary()
{
    /// check if need more cap
    if (m_size == m_capacity) {
        m_capacity = static_cast<int>(capacity_increase_coef * static_cast<float>(m_capacity));
        reallocate();
        return;
    }

    /// check if need less cap
    if (m_size < should_care_threshold) {
        return;
    }

    if (m_capacity / m_size > capacity_size_diff_normalize_coef) {
        m_capacity /= capacity_size_diff_normalize_coef;
        reallocate();
    }
}

template<typename T>
void Vector<T>::reallocate()
{
    T* new_data = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        new_data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_data;
}

}
}
