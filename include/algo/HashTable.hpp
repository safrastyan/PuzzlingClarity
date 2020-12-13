#pragma once

#include <string>
#include <vector>
#include <functional>


namespace pc {
namespace algo {

/// KEY_TYPE is the KEY_TYPE for the hash function. We are using this to combine all the points a, b, c and d into one class
template<typename KEY, typename VAL>
class HashTable
{
public:
    HashTable(int size);

    void set_hash_function(std::function<int(const KEY&)>);

    /// add a new name to the table
    void add(const KEY&, const VAL&);

    ///check whether the current name exists
    bool exists(const KEY&);

    /// return the element tied to the passed key
    VAL get(const KEY&) const;

    void replace_element(const KEY&, const VAL&);

    /// problem specific consts
    static constexpr int HASH_SIZE_a = 2048;
    static constexpr int HASH_SIZE_b = 2048;
    static constexpr int HASH_SIZE_c = 10000;
    static constexpr int HASH_SIZE_d = 10000;
    
private:

    std::vector<std::vector<std::pair<KEY, VAL>>> m_table;
    std::function<int(const KEY&)> m_hash;
};

}
}
}

#include "algo/HashTable_impl.hpp"