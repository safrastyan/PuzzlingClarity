#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <cctype>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

int t, n, b, p;

bool worthit(int x)
{
    return x >= 7;
}

class A
{
public:
    A(int s): blocks(s){}

    int place(int x); ////bouncing ball
    int place_basic(int x);


    int ready_to_complete() const; /// block index which is one short towards completion., -1 optherwise

    int xurd() const ;/// block which is less than n - 1 and can take a xurded number

    std::vector<std::vector<int>> blocks;

    void pretty_print()
    {
        std::cout << std::endl;
        for (int i = 0; i < blocks.size(); ++i) {
            for (int j = blocks[i].size() - 1; j >= 0; --j) {
                std::cout << blocks[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};


int A::place(int x)
{
    if (worthit(x)) {
        int p = ready_to_complete();
        if (p != -1) {
            blocks[p].push_back(x);
            return p;
        }
    }
    

    for (int i = 0; i < blocks.size(); ++i) {
        if (blocks[i].size() == n) {
            continue;
        }
        if (blocks[i].size() == 0) {
            blocks[i].push_back(x);
            return i;
        }
        if (x >= blocks[i].back()) {
            blocks[i].push_back(x);
            return i;
        }
    }
    
    for (int i = 0; i < blocks.size(); ++i) {
        if (blocks[i].size() != n) {
            blocks[i].push_back(x);
            return i;
        }
    }
}

int A::place_basic(int x)
{
    if (worthit(x)) {
        int p = ready_to_complete();
        if (p != -1) {
            blocks[p].push_back(x);
            return p;
        }
    }
    int p = xurd();
    blocks[p].push_back(x);
    return p;
}


int A::ready_to_complete() const
{
    for (int i = 0; i < blocks.size(); ++i) {
        if (blocks[i].size() == n - 1) {
            return i;
        }
    }
    return -1;
}

int A::xurd() const
{
    for (int i = 0; i < blocks.size(); ++i) {
        if (blocks[i].size() < n - 1) {
            return i;
        }
    }
    return ready_to_complete();
}


void solve()
{
    A a(b);
    for (int i = 0; i < n * b; ++i) {
        int x;
        std::cin >> x;
        std::cout << a.place(x) + 1 << std::endl;
    //   a.pretty_print();
    }
}

int main()
{
    std::cin >> t >> n >> b >> p;
    for (int i = 0; i < t; ++i) {
        solve();
    }
  
    return 0;
}