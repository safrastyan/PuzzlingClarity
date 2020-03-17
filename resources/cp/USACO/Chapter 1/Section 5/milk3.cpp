/*
ID: safrast1
TASK: milk3
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

std::vector<int> pour(const std::vector<int>& bs, int s, int d, const std::vector<int>& lims)
{
    auto res = bs;
    if (bs[s] + bs[d] <= lims[d]) {
        res[d] += res[s];
        res[s] = 0;
    } else {
        int dif = lims[d] - res[d];
        res[d] += dif;
        res[s] -= dif;
    }
    return res;
}

bool operator < (const std::vector<int>& v1, const std::vector<int>& v2)
{
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] < v2[i]) {
            return true;
        }
    }
    return false;
}

int main() 
{
    std::ifstream fin ("milk3.in");
    std::ofstream fout ("milk3.out");
    
    int a, b, c;
    fin >> a >> b >> c;
    std::vector<int> bs(3, 0);
    std::vector<int> lims = {a, b, c};
    bs[2] = c;
    std::queue<std::vector<int>> q;
    std::set<std::vector<int>> visited;
    q.push(bs);
    visited.insert(bs);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        std::vector<std::vector<int>> new_ress;
        new_ress.push_back(pour(v, 0, 1, lims));
        new_ress.push_back(pour(v, 1, 0, lims));
        new_ress.push_back(pour(v, 1, 2, lims));
        new_ress.push_back(pour(v, 2, 1, lims));
        new_ress.push_back(pour(v, 0, 2, lims));
        new_ress.push_back(pour(v, 2, 0, lims));
        for (const auto& vv: new_ress) {
            if (visited.find(vv) == visited.end()) {
                visited.insert(vv);
                q.push(vv);
            }
        }
    }

    std::set<int> res;
    for (const auto& v: visited) {
        if (v[0] == 0) {
            res.insert(v[2]);
        }
    }
    int x = 0;
    for (auto c : res) {
        ++x;
        fout << c;
        if (x != res.size()) {
            fout << " ";
        }
    }
    fout << std::endl;

    return 0;
}