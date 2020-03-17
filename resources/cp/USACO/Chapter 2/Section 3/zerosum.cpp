/*
ID: safrast1
TASK: zerosum
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

std::string to_str(const std::vector<int>& nums, const std::vector<char>& actions)
{
    std::string s;
    for (int i = 0; i < nums.size(); ++i) {
        s.push_back(nums[i] +'0');
        if (i != nums.size() - 1) {
            s.push_back(actions[i]);
        }
    }
    return s;
}

bool check(const std::vector<int>& nums, const std::vector<char>& actions)
{
    int sum = 0;

    int ten = 1;
    int cur_num = nums.back();
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (actions[i] == ' ') {
            ten *= 10;
            cur_num += ten * nums[i];
            continue;
        }
        sum += actions[i] == '+' ? cur_num : -cur_num;
        cur_num = nums[i];
        ten = 1;
    }
    sum += cur_num;

    return sum == 0;
}

void collect(const std::vector<int>& nums, std::vector<char>& actions, std::set<std::string>& res)
{
    if (actions.size() == nums.size() - 1) {
        if (check(nums, actions)) {
            res.insert(to_str(nums, actions));
        }
        return;
    }
    static std::vector<char> a{'+', '-', ' '};
    for (auto c: a) {
        actions.push_back(c);
        collect(nums, actions, res);
        actions.pop_back();
    }
}

int main() 
{
    std::ifstream fin ("zerosum.in");
    std::ofstream fout ("zerosum.out");
    int n;
    fin >> n;
    std::vector<int> nums;
    for (int i = 1; i <= n; ++i) {
        nums.push_back(i);
    }    
    std::set<std::string> res;
    std::vector<char> actions;
    
    collect(nums, actions, res);

    for (const auto& s: res) {
        fout << s << std::endl;
    }

    return 0;
}