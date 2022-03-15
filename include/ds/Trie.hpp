#pragma once

#include <vector>
#include <string>

namespace pc {
namespace ds {

struct TNode
{
    TNode();

    std::vector<TNode*> nodes;
    bool is_word;
};

class Trie
{
public:
    Trie();
    void add_word(const std::string& word);
    bool exists(const std::string& word) const;

private:
    TNode* m_root;
};

}
}
