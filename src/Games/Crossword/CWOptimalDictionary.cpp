#include "Games/Crossword/CWOptimalDictionary.hpp"
#include "io/io.hpp"

#include <fstream>
#include <cctype>

namespace pc {
namespace games {
namespace crossword {


CWOptimalDictionary::CWOptimalDictionary(const std::string& path): m_id_to_word()
                                                                 , m_word_to_id()
                                                                 , m_pos_letter_list()
{
    std::ifstream fin(path);
    auto words = io::read_dictionary(fin);
    for (auto& s: words) {
        for (int i = 0; i < s.size(); ++i) {
            if (!std::isalpha(s[i])) {
                s = "";
                break;
            }
            s[i] = std::tolower(s[i]);
        }

        if (!s.empty()) {
            m_id_to_word.push_back(s);
        }
    }

    m_longst_word_len = 0;
    for (const auto& s: m_id_to_word) {
        m_longst_word_len = std::max(m_longst_word_len, static_cast<int>(s.size()));
    }
}   

void CWOptimalDictionary::serialize_word_to_id()
{
    for (int i = 0; i < m_id_to_word.size(); ++i) {
        m_word_to_id[m_id_to_word[i]] = i;
    }
}

void CWOptimalDictionary::serialize_pos_to_letter_list()
{

}

int CWOptimalDictionary::word_count() const 
{
    return m_id_to_word.size();
}

int CWOptimalDictionary::longest_word_length() const
{
    return m_longst_word_len;
}

std::vector<std::string> CWOptimalDictionary::all_words() const
{
    return m_id_to_word;
}

std::string CWOptimalDictionary::random_word() const
{
    int r = std::rand() % word_count();
    return m_id_to_word[r];
}

}
}
}