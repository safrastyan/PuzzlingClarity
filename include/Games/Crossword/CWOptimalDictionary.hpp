#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>

namespace pc {
namespace games {
namespace crossword {

/**
 * @brief A special dictionary for crossword style of games. serializes a lot of data , based on letters and all 
 */
class CWOptimalDictionary 
{
public:
    /// The constructor is gonna automatically load and filter, so be carefully when creating this object. 
    CWOptimalDictionary(const std::string& path);
    
    void serialize_word_to_id();
    void serialize_len_pos_letter_set();

    /// returns word_count
    int word_count() const;
    int longest_word_length() const;

    const std::string& word_by_id(int id) const;
    int id_by_word(const std::string&);
    

    std::vector<std::string> all_words() const;
    std::string random_word() const;

    std::set<int> all_words_for_len(int len) const;

    const std::set<int>& set_by_len_pos_letter(int len, int pos, int letter) const;

private:

    //// a lot of data here, might delete some later
    std::vector<std::string> m_id_to_word;
    std::map<std::string, int> m_word_to_id;
    
    /// this is a big one
    std::vector<std::vector<std::vector<std::set<int>>>> m_len_pos_letter_set;

    std::vector<std::set<int>> m_len_set;

    int m_longst_word_len;
};

inline const std::string& CWOptimalDictionary::word_by_id(int id) const
{
    return m_id_to_word[id];
}

inline int CWOptimalDictionary::id_by_word(const std::string& w)
{
    return m_word_to_id[w];
}

inline std::set<int> CWOptimalDictionary::all_words_for_len(int len) const
{
    return m_len_set[len];
}

inline const std::set<int>& CWOptimalDictionary::set_by_len_pos_letter(int len, int pos, int letter) const
{
    return m_len_pos_letter_set[len][pos][letter];
}

}
}
}