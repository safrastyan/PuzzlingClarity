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
	std::unordered_map<std::string, int> a;
	std::cin >> n;
	std::string s;
	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		if (a.find(s) == a.end()) {
			std::cout << s << std::endl;
		} else {
			std::cout << s << "(" << a[s] << ")" << std::endl;
		}
		++a[s];
	}
	return 0;
}
