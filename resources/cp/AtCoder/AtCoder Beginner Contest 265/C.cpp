#include <bits/stdc++.h>


constexpr int NINF = std::numeric_limits<int>::min();
constexpr int INF = std::numeric_limits<int>::max();

template<typename T>
T inf();
template<typename T>
T ninf();
template<typename T>
std::vector<T> reada();
template<typename T>
std::vector<T> reada(int n);
std::vector<int> readai();
std::vector<int> readai(int n);


template <typename T> using vc = std::vector<T>;
template <typename T> using vvc = std::vector<vc<T>>;
template <typename T> using vvvc = std::vector<vvc<T>>;
using ll=long long;
using ull = unsigned long long;




int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a;
	for (int i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		a.push_back(s);
	}
	
	std::vector<std::vector<char>> mark(n, std::vector<char>(m, 0));
	mark[0][0] = 1;
	int r = 0;
	int c = 0;
	
	while (true) {
		int nr, nc;
		if (a[r][c] == 'U') {
			nr = r - 1;
			nc = c;
		}
		if (a[r][c] == 'D') {
			nr = r + 1;
			nc = c;
		}
		if (a[r][c] == 'L') {
			nr = r;
			nc = c - 1;
		}
		if (a[r][c] == 'R') {
			nr = r;
			nc = c + 1;
		}
		if (nr < 0 || nc < 0 || nr >= a.size() || nc >= a[0].size()) {
			std::cout << r + 1 << " " << c + 1 << std::endl;
			return 0;
		}
		if (mark[nr][nc] == 1) {
			std::cout << -1 << std::endl;
			return 0;
		}
		mark[nr][nc] = 1;
		r = nr;
		c = nc;
	}
	return 0;
}



template<typename T>
inline T inf()
{
	return std::numeric_limits<T>::max();
}

template<typename T>
inline T ninf()
{
	return std::numeric_limits<T>::min();
}


template <typename T>
inline std::vector<T> reada()
{
	int n;
	std::cin >> n;
	return reada<T>(n);
}


template<typename T>
inline std::vector<T> reada(int n)
{
	std::vector<T> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	return a;
}

std::vector<int> readai(int n)
{
	return reada<int>(n);
}

std::vector<int> readai()
{
	return reada<int>();
}
