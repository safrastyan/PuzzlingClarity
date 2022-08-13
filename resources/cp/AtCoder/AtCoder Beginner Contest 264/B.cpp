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
	int r, c;
	std::cin >> r >> c;
	int n = 15;

	vc<vc<int>> a(n, vc<int>(n, 0));

	for (int i = 0; i < n / 2; i += 2) {
		for (int j = i; j < n - i; ++j) {
			a[i][j] = 1;
			a[i][n - j - 1] = 1;
			a[n - i - 1][j] = 1;
			a[n - i - 1][n - j - 1] = 1;

			a[j][i] = 1;
			a[n - j - 1][i] = 1;
			a[j][n - i - 1] = 1;
			a[n - j - 1][n - i - 1] = 1;
		}
	}

	
	std::cout << (a[r - 1][c - 1] == 1 ? "black" : "white") << std::endl;
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
