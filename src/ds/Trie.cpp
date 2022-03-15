#include "ds/Trie.hpp"


namespace pc {
namespace ds {

TNode::TNode(): nodes(26, nullptr)
                     , is_word(false)
{}


Trie::Trie(): m_root(new TNode())
{}

void Trie::add_word(const std::string& word)
{
    TNode* cur = m_root;
    for (int i = 0; i < word.size(); ++i) {
        int j = static_cast<int>(word[i] - 'a');
        if (cur->nodes[j] == nullptr) {
            cur->nodes[j] = new TNode();
        }
        cur = cur->nodes[j];
    }
    cur->is_word = true;
}

bool Trie::exists(const std::string& word) const
{
    TNode* cur = m_root;
    for (char c: word) {
        int j = static_cast<int>(c - 'a');
        if (cur->nodes[j] == nullptr) {
            return false;
        }
        cur = cur->nodes[j];
    }
    return cur->is_word;
}

}
}
