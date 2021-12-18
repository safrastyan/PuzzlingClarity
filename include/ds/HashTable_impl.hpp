#pragma once 


namespace pc {
namespace ds {


template<typename KEY, typename VAL>
inline HashTable<KEY, VAL>::HashTable(int size): m_table(size)
{}

template<typename KEY, typename VAL>
void HashTable<KEY, VAL>::set_hash_function(std::function<int(const KEY&)> hash)
{
    m_hash = hash;
}

template<typename KEY, typename VAL>
void HashTable<KEY, VAL>::add(const KEY& key, const VAL& val)
{
    auto k = m_hash(key) % m_table.size();
    for (int i = 0; i < m_table[k].size(); ++i) {
        if (m_table[k][i].first == key) {
            return;
        }
    }
    m_table[k].push_back(std::make_pair(key, val));
}

template<typename KEY, typename VAL>
bool HashTable<KEY, VAL>::exists(const KEY& key)
{
    auto k = m_hash(key) % m_table.size();
    for (const auto& elem: m_table[k]) {
        if (elem.first == key) {
            return true;
        }
    }
}

template<typename KEY, typename VAL>
VAL HashTable<KEY, VAL>::get(const KEY& key) const
{
    auto k = m_hash(key) % m_table.size();
    for (const auto& elem: m_table[k]) {
        if (elem.first == key) {
            return elem.second;
        }
    }
    return VAL();
}


template<typename KEY, typename VAL>
void HashTable<KEY, VAL>::replace_element(const KEY& key, const VAL& new_val)
{
    auto k = m_hash(key) % m_table.size();
    for (auto& elem: m_table[k]) {
        if (elem.first == key) {
            elem.second = new_val;
            return;
        }
    }
}


}
}
