/*
ID: safrast1
TASK: wormhole
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

using pair=std::vector<std::pair<unsigned int ,unsigned int>>;

bool is_portal(const pair& p, int i)
{
    for (const auto& pp: p) {
        if (pp.first == i || pp.second == i) {
            return true;
        }
    }
    return false;
}

int find_portal_pair(const pair& p, int i)
{
    for (const auto& pp: p) {
        if (pp.first == i) {
            return pp.second;
        }
        if (pp.second == i) {
            return pp.first;
        }
    }
}

int find_next_node(const pair& a, unsigned int x, unsigned int y)
{
    auto rx = x;
    int res_i = -1;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].first > x && a[i].second == y) {
            if (res_i == -1) {
                rx = a[i].first;
                res_i = i;
            }
            if (a[i].first < rx) {
                rx = a[i].first;
                res_i = i;
            }
            
        }
    }

    return res_i;
}

bool is_loop(const pair& p, const pair& a)
{
    int n = a.size();
    bool any_loop = false; 
    std::vector<int> is_portal_v(a.size(), 0);
    for (int i = 0; i < n; ++i) {
        int jumps = 0;
        auto cur_x = a[i].first;
        auto cur_y = a[i].second;
        while (jumps < 100) {  
            int next = find_next_node(a, cur_x, cur_y);
            if (next == -1) {
                break;
            }
            if (!is_portal(p, next)) {
                cur_x = a[next].first;
                cur_y = a[next].second;
                continue;
            }
            ++jumps;
            
            int n_next = find_portal_pair(p, next);
            cur_x = a[n_next].first;
            cur_y = a[n_next].second;
         }
        
         if (jumps >= 100) {
             any_loop = true;
             break;
         }
    }
    return any_loop;
}

bool operator == (const pair& p1, const pair& p2)
{
    for (int i = 0; i < p1.size(); ++i) {
        if (p1[i].first != p2[i].first || p1[i].second != p2[i].second) {
            return true;
        }
    }
    return false;
}

bool operator < (const pair& p1, const pair& p2)
{
    for (int i = 0; i < p1.size(); ++i) {
        if (p1[i].first < p2[i].first || p1[i].second < p2[i].second) {
            return true;
        }
    }
    return false;
}

void take(std::set<pair>& col, std::vector<int>& b)
{
    pair p(b.size() / 2, std::make_pair(-1, -1));
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == -1) {
            continue;
        }
        if (p[b[i]].first == -1) {
            p[b[i]].first = i;
        } else {
            p[b[i]].second = i;
        }
    }
 
    std::sort(p.begin(), p.end());
    col.insert(p);
}

void collect_pairs(std::set<pair>& col, int n)
{
    std::vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }

    std::vector<int> b;
    if (n % 2 != 0) {
        b.push_back(-1);
    }
    for (int i = 0; i < n / 2; ++i) {
        b.push_back(i);
        b.push_back(i);
    }
    
    take(col, b);

    while (std::next_permutation(b.begin() + 1, b.end())) {
        take(col, b);
    }
}


int main() 
{
    std::ifstream fin ("wormhole.in");
    std::ofstream fout ("wormhole.out");
  

    int n;
    fin >> n;
    pair cords(n);
    for (int i = 0; i < n; ++i) {
        fin >> cords[i].first >> cords[i].second;
    }

    std::set<pair> filter;
    collect_pairs(filter, n);

    int res = 0;
    for (const auto& p: filter) {
        if (is_loop(p, cords)) {
            ++res;
        } 
    }

    fout << res << std::endl;
    return 0;
}