#pragma once

namespace pc {
namespace Games {

template<typename S>
inline Bet<S>::Bet(const std::string& name, std::function<bool(S)> checker, float coef): m_name(name)
                                                                                , m_checker(checker)
                                                                                , m_coef(coef)
{}


template<typename S>
inline bool Bet<S>::check(const S& s) const
{
    return m_checker(s);
}

template<typename S>
inline std::string Bet<S>::name() const 
{
    return m_name;
}

template<typename S>
inline double Bet<S>::coef() const
{
    return m_coef;
}


}
}
