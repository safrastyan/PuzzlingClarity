/*
ID: safrast1
TASK: holstein
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

template<typename T>
inline std::vector<std::vector<T>> generate_all_subsets(const std::vector<T>& a)
{
    std::vector<std::vector<T>> res;

    for (int i = 0; i < (1 << a.size()); ++i) {
        std::vector<char> mask(a.size());
        std::vector<T> cur_res;

        int n = i;
        int j = 0;
        while (n != 0) {
            mask[j] = n % 2;
            n /= 2;
            ++j;    
        }
        for (int j = 0; j < mask.size(); ++j) {
            if (mask[j] == 1) {
                cur_res.push_back(a[j]);
            }
        }
        res.push_back(cur_res);
    }
    return res;
}


bool check(const std::vector<int>& req, const std::vector<std::vector<int>>& sub_feed)
{
    std::vector<int> a(req.size(), 0);
    for (int i = 0; i < sub_feed.size(); ++i) {
        for (int j = 0; j < sub_feed[0].size(); ++j) {
            a[j] += sub_feed[i][j];
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < req[i]) {
            return false;
        }
    }
    return true;
}

int main() 
{
    std::ifstream fin ("holstein.in");
    std::ofstream fout ("holstein.out");
    

    int n;
    fin >> n;
    std::vector<int> req(n);
    for (int i = 0; i < n; ++i) {
        fin >> req[i];
    }
    int m;
    fin >> m;
    std::vector<std::vector<int>> feeds(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> feeds[i][j];
        }
    }

    std::vector<int> ind(m);
    for (int i = 0; i < m; ++i) {
        ind[i] = i;
    }
    auto subs = generate_all_subsets(ind);
    
    unsigned long ans_len = m;
    std::vector<int> ans = ind;

    for (const auto& sub: subs) {
        std::vector<std::vector<int>> ch;
        if (sub.size() > ans_len) {
            continue;
        }

        for (auto x: sub) {
            ch.push_back(feeds[x]);
        }
        if (check(req, ch) && ans_len > ch.size()) {
            ans_len = ch.size();
            ans = sub;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        ++ans[i];
    }
    fout << ans_len << " ";
    for (int i = 0; i < ans.size() - 1; ++i) {
        fout << ans[i] << " ";
    }
    fout << ans.back() << std::endl;
    return 0;
}