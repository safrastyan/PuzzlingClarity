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


struct Intervals
{
	Intervals(int n): a(n, 0)
	{

	}
	std::vector<int> a;

};

Intervals extr(const std::vector<long long>& a, const std::vector<long long>& sum, long long target)
{
	Intervals in(a.size());
	for (int i = 0; i < sum.size(); ++i) {
		long long tt;
		if (i == 0) {
			tt = target;
		} else {
			tt = sum[ i -1] + target;
		}

		auto f = std::lower_bound(sum.begin() + i, sum.end(), tt);
		if (f != sum.end() && *f == tt) {
			in.a[i] = f - sum.begin();
		}
		
	}
	return in;
}

int main()
{
	std::ios::sync_with_stdio(false);
	long long n, p, q, r;
	std::cin >> n >> p >> q >> r;
	std::vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	if (a.size() == 3) {
		if (a[0] == p && a[1] == q && a[2] == r) {
			std::cout << "Yes";
		} else {
			std::cout << "No'";
		}
		return 0;
	}


	std::vector<long long> sum(a.size(), 0);
	sum[0] = a[0];
	for (int i = 1; i < a.size(); ++i) {
		sum[i] = sum[i - 1] + a[i];
	}



	auto i1 = extr(a, sum, p);
	auto i2 = extr(a, sum, q);
	auto i3 = extr(a, sum, r);
	for (int i = 0; i < i1.a.size(); ++i) {
		if (i1.a[i] == 0) {
			continue;
		}
		int c1 = i1.a[i] + 1;
		if (i2.a[c1] == 0) {
			continue;
		}
		int c2 = i2.a[c1] + 1;
		if (i3.a[c2] == 0) {
			continue;
		}
		std::cout << "Yes" << std::endl;
		return 0;
	}
	std::cout << "No" << std::endl;
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
