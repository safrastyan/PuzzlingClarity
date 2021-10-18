#pragma once

namespace pc {
namespace Games {
namespace Analyzers {


template<typename S>
inline Expectation<S>::Expectation(const std::vector<S>& data, const std::vector<Bet<S>>& bets): m_states(data)
                                                                                               , m_bets(bets)
{}

template<typename S>
inline std::vector<std::pair<Bet<S>, double>> Expectation<S>::calc_all() const
{
    std::vector<std::pair<Bet<S>, double>> res;
    for (const auto& b: m_bets) {
        int success_times = 0;
        for (const auto& s: m_states) {
            if (b.check(s)) {
                ++success_times;
            }
        }
        res.push_back(std::make_pair(b, (static_cast<double>(success_times) / m_states.size()) * b.coef() ));
    }
    return res;
}

template<typename S>
inline std::pair<Bet<S>, double> Expectation<S>::best_bet() const
{
    /// TODO this is the worst way of doing this, also we might not even need this
    auto all = this->calc_all();

    int best_ind = 0;
    double best_ret = all[0].second;
    for (int i = 1; i < all.size(); ++i) {
        if (all[i].second > best_ret) {
            best_ret = all[0].second;
            best_ind = i;
        }
    }
    return std::make_pair(all[best_ind].first, best_ret);
}

}
}
}
