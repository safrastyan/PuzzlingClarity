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


std::pair<vc<int>, vc<int>> extract(const vc<vc<int>>& a)
{
	vc<int> even;
	vc<int> odd;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].size(); ++j) {
			if ( (i + j) % 2 == 0) {
				even.push_back(a[i][j]);
				continue;
			}
			odd.push_back(a[i][j]);
		}
	}
	std::sort(even.begin(), even.end());
	std::sort(odd.begin(), odd.end());
	return std::make_pair(even, odd);
}

bool same(const vc<int>& a, const vc<int>& b)
{
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

vc<int> flatten(const vc<vc<int>>& a)
{
	vc<int> res;
	for (const auto& vec: a) {
		for (auto aa: vec) {
			res.push_back(aa);
		}
	}
	return res;
}

void solve(int tt)
{
	int n, m;
	std::cin >> n >> m;
	vvc<int> a(n, vc<int>(m));
	auto b = a;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> b[i][j];
		}
	}	

	if (n == 1 || m == 1) {
		auto f1 = flatten(a);
		auto f2 = flatten(b);
		std::cout << (same(f1, f2) ? "YES" : "NO") << std::endl;
		return;
	}

	auto r1 = extract(a);
	auto r2 = extract(b);
	
	std::cout << (same(r1.first, r2.first) && same(r1.second, r2.second) ? "YES": "NO") << std::endl;
	

}

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	for (int k = 1; k <= t; ++k) {
		solve(k);
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
