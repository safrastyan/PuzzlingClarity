/*
ID: safrast1
TASK: beads
LANG: C++11          
*/

#include <iostream>
#include <fstream>
#include <string>

int test(std::string s)
{
	int res = 0;
	///who cares about the time
	while (!s.empty()) {
		if (s.size() == 1) {
			return res + 1;
		}
		if (s[0] != s[1] && s[0] != 'w' && s[1] != 'w') {
			++res;
			break;
		}
		if (s[1] == 'w') {
			s[1] = s[0];
		}
		if (s[0] == 'w') {
			s[0] = s[1];
		}
		++res;
		s.erase(0, 1);
	}

	while (!s.empty()) {
		if (s.size() == 1) {
			return res + 1;
		}

		int i1 = s.size() - 1;
		int i2 = s.size() - 2;

		if (s[i1] != s[i2] && s[i1] != 'w' && s[i2] != 'w') {
			++res;
			break;
		}

		if (s[i2] == 'w') {
			s[i2] = s[i1];
		}
		if (s[i1] == 'w') {
			s[i1] = s[i2];
		}
		++res;
		s.pop_back();
	}
	return res;
}
int main() 
{
    std::ofstream fout ("beads.out");
    std::ifstream fin ("beads.in");
	std::string s;
	int n;
	fin >> n;
	fin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		std::string cut = s.substr(i, s.size() - i) + s.substr(0, i);
		ans = std::max(ans, test(cut));
	}
	fout << ans << std::endl;
    return 0;
}