#define BOOST_TEST_MODULE CWOptimalDictionary
#include <boost/test/unit_test.hpp>

#define private public

#include "Games/Crossword/CWOptimalDictionary.hpp"
#include "Base/Paths.hpp"

#include <algorithm>
#include <iostream>

using namespace pc::games::crossword;
using namespace pc::base::paths;

CWOptimalDictionary* d;

BOOST_AUTO_TEST_SUITE(CWOptimalDictionary_tests)

BOOST_AUTO_TEST_CASE(after_loading_test)
{
    std::srand(time(0));
    d = new CWOptimalDictionary(linx_standard_dictionary_path());
    BOOST_CHECK(d->word_count() > 0);
    std::cout << "PRinting the whole state";
    for (auto s: d->m_id_to_word) {
        std::cout << s << std::endl;
    }
}   

BOOST_AUTO_TEST_CASE(serializations_test)
{
    d->serialize_word_to_id();  
    auto w = d->random_word();
    
    BOOST_CHECK(d->m_id_to_word[d->m_word_to_id[w]] == w);

    d->serialize_pos_to_letter_list();
    w = d->random_word();
    int id = d->m_word_to_id[w];
    for (int i = 0; i < w.size(); ++i) {
        auto& vec = d->m_pos_letter_list[w[i] - 'a'][i];
        auto f = std::find(vec.begin(), vec.end(), id);
        BOOST_CHECK(f != vec.end());
    }
}

BOOST_AUTO_TEST_SUITE_END()
