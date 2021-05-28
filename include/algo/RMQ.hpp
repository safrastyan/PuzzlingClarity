#pragma once

#include <vector>


namespace pc {
namespace algo {

class RMQ
{
public:
    RMQ(const std::vector<int>& arr, bool rmq_min = true);

    //Query range to get min or max element
    int query(int start, int end) const;
    
private:
    void construct_heap(const std::vector<int>& arr);

    std::vector<int> m_heap;
    bool m_rmq_min;
};

}
}