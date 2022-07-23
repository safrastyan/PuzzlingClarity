#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;
using ll=long long;
using ull = unsigned long long;


int main()
{
	int n;
	std::cin >> n;
	std::vector<std::string> a;
	for (int i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		a.push_back(s);
	}
	bool ans = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				if (a[i][j] != '-') {
					ans = false;
				}
				continue;
			}
			

			char c1 = a[i][j];
			char c2 = a[j][i];
			if (c1 == 'D' && c2 == 'D') {
				continue;
			}
			if (c1 == 'W' && c2 == 'L') {
				continue;
			}
			if (c1 == 'L' && c2 == 'W') {
				continue;
			}
			ans = false;
		}
	}
	std::cout << (ans ? "correct" : "incorrect") << std::endl;
	return 0;
}
