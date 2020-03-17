/*
ID: safrast1
TASK: namenum
LANG: C++11          
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

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

inline TNode::TNode(): nodes(26, nullptr)
                     , is_word(false)
{}


inline Trie::Trie(): m_root(new TNode())
{}

inline void Trie::add_word(const std::string& word)
{
    TNode* cur = m_root;
    for (int i = 0; i < word.size(); ++i) {
        int j = static_cast<int>(word[i] - 'A');
        if (cur->nodes[j] == nullptr) {
            cur->nodes[j] = new TNode();
        }
        cur = cur->nodes[j];
    }
    cur->is_word = true;
}

inline bool Trie::exists(const std::string& word) const
{
    TNode* cur = m_root;
    for (char c: word) {
        int j = static_cast<int>(c - 'A');
        if (cur->nodes[j] == nullptr) {
            return false;
        }
        cur = cur->nodes[j];
    }
    return cur->is_word;
}

void collect_names(std::string& n, std::string& collected, int p, std::vector<std::string>& all_names, std::vector<std::string>& maps, Trie& t)
{
    if (p == n.size()) {
        if (t.exists(collected)) {
            all_names.push_back(collected);
        }
        return;
    }
    int x = static_cast<int>(n[p] - '2');
    for (int i = 0; i < maps[x].size(); ++i) {
        collected.push_back(maps[x][i]);
        collect_names(n, collected, p + 1, all_names, maps, t);
        collected.pop_back();
    }
}

int main()
{
    std::ifstream fdict("dict.txt");
    std::ifstream fin("namenum.in");
    std::ofstream fout("namenum.out");

    std::vector<std::string> maps = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

    Trie t;
    std::string word;
    while (fdict >> word) {
        t.add_word(word);
    }

    std::string n;
    fin >> n;

    std::string collected;
    std::vector<std::string> all_names;

    collect_names(n, collected, 0, all_names, maps, t);
    std::sort(all_names.begin(), all_names.end());
    for (const auto& s: all_names) {
        fout << s << std::endl;
    }
    if (all_names.empty()) {
        fout << "NONE" << std::endl;
    }
    return 0;
}