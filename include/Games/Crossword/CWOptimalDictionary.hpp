#pragma once

#include <string>
#include <vector>
#include <map>

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
    void serialize_pos_to_letter_list();

    /// returns word_count
    int word_count() const;
    int longest_word_length() const;


    std::vector<std::string> all_words() const;
    std::string random_word() const;

private:

    //// a lot of data here, might delete some later
    std::vector<std::string> m_id_to_word;
    std::map<std::string, int> m_word_to_id;
    
    /// this is a big one
    std::vector<std::vector<std::vector<int>>> m_pos_letter_list;

    int m_longst_word_len;
};
}
}
}