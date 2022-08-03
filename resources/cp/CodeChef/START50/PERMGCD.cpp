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



void solve(int tt)
{
	int n, x;
	std::cin >> n >> x;
	if (x < n) {
		std::cout << -1 << std::endl;
		return;
	}
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = i + 1;
	}
	
	std::swap(a[0], a[x - n]);
	std::sort(a.begin() + 1, a.end());
	for (auto aa : a) {
		std::cout << aa << " ";
	}
	std::cout << std::endl;
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
	std::vector<int> a(n);
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