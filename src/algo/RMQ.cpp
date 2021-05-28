#include "algo/RMQ.hpp"

#include <vector>

namespace pc {
namespace algo {

RMQ::RMQ(const std::vector<int>& arr, bool rmq_min) : m_rmq_min(rmq_min)
{
    construct_heap(arr);
}

int RMQ::query(int start, int end) const
{
    return 0;
}

void RMQ::construct_heap(const std::vector<int>& arr) 
{

}

}

}