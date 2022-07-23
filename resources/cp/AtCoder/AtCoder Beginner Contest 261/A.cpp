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
	std::vector<int> a(10000, 0);
	int x, y;
	std::cin >> x >> y;
	for (int i = x; i <= y; ++i) {
		++a[i];
	}
	std::cin >> x >> y;
	for (int i = x; i <= y; ++i) {
		++a[i];
	}
	int r = std::count(a.begin(), a.end(), 2);
	if (r != 0) {
		--r;
	}
	std::cout << r << std::endl;
	return 0;
}
