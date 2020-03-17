/*
ID: safrast1
TASK: prefix
LANG: C++11          
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <array>
#include <cassert>

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

    TNode* m_root;
};

TNode::TNode(): nodes(26, nullptr)
                     , is_word(false)
{}


Trie::Trie(): m_root(new TNode())
{}

void Trie::add_word(const std::string& word)
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

bool Trie::exists(const std::string& word) const
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

void checkWord(const std::string& word, int& best, TNode* root)
{

    std::set<std::pair<int, TNode*>> mark;

    std::stack<std::pair<int, TNode*>> s;
    s.push(std::make_pair(0, root->nodes[word[0] - 'A']));
    while (!s.empty()) {
        auto nod = s.top().second;
        int in_d = s.top().first;
        s.pop();

        if (nod == nullptr) {
            continue;
        }
        if (nod->is_word) {
            best = std::max(best, in_d + 1);
            if (in_d != word.size() - 1) {
                auto new_x = std::make_pair(in_d + 1, root->nodes[word[in_d + 1] - 'A']);
                if (new_x.second != nullptr) {
                    if (mark.find(new_x) == mark.end()) {
                        mark.insert(new_x);
                        s.push(new_x);
                    }
                }
            }
        }
        if (in_d != word.size() - 1) {
            auto new_x = std::make_pair(in_d + 1, nod->nodes[word[in_d + 1] - 'A']);
            if (new_x.second != nullptr) {
                if (mark.find(new_x) == mark.end()) {
                    mark.insert(new_x);
                    s.push(new_x);
                } 
            }
        }
    }
}

Trie build(const std::vector<std::string>& words)
{
    Trie t;
    for (const auto& w: words) {
        t.add_word(w);
    }
    return t;
}


void collect_nodes_for_clean(std::vector<TNode*>& res, TNode* t)
{
    if (t == nullptr) {
        return;
    }
    res.push_back(t);
    for (int i = 0; i < 26; ++i) {
        collect_nodes_for_clean(res, t->nodes[i]);
    }
}

void clean (Trie& t)
{
    std::vector<TNode*> ts;
    collect_nodes_for_clean(ts, t.m_root);
    for (int i = 0;i < ts.size(); ++i) {
        delete ts[i];
    }
}


std::vector<std::string> filter_prims(const std::vector<std::string>& words)
{
   
    std::vector<std::string> res = words;
    bool done = false;
    while (!done) {
        done = true;
        for (int i = 0; i < res.size(); ++i) {
            if (res[i].size() == 1) {
                continue;
            }

            std::string s = res[i];
            auto temp = res;
            temp.erase(temp.begin() + i, temp.begin() + i + 1);
        
            auto tree = build(temp);
            int best = 0;
            checkWord(s, best, tree.m_root);
            if (best == s.size()) {
                res = temp;
                done = false;
                clean(tree);
                break;
            }
            clean(tree);
        }
    }
    
    return res;
}




int main() 
{
    std::ifstream fin ("prefix.in");
    std::ofstream fout ("prefix.out");
    
    std::string s;
    std::vector<std::string> prims;
    while (fin >> s) {
        if (s == ".") {
            break;
        }
        prims.push_back(s);
    }


    std::cout << "Didn't reach here " << std::endl;
    auto filtered = filter_prims(prims);
    
    auto t = build(filtered);
    std::string ss;
    s.clear();
    while (fin >> ss) {
        if (ss.size() == 0) {
            break;
        }
        if (std::isalnum(ss[0])) {
            s+= ss;
        }
    }

    int res = 0;
    std::cout << "Reached here " << std::endl;
    checkWord(s, res, t.m_root);
    fout << res << std::endl;
    return 0;
}