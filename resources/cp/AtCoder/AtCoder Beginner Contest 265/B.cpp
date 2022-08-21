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
	long long t;
	std::cin >> n >> m >> t;
	auto a = reada<long long>(n - 1);
	std::vector<int> b(a.size(), 0);
	for (int i = 0; i < m; ++i) {
		int p, q;
		std::cin >> p >> q;
		b[p - 2] = q;
	}

	for (int i = 0; i < a.size(); ++i) {
		if (t <= a[i]) {
			std::cout << "No" << std::endl;
			return 0;
		}
		t -= a[i];
		t += b[i];
	}
	std::cout << "Yes" << std::endl;
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
