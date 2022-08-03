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


std::pair<ll, ll> try_from(ll x, ll left, ll right)
{
	if (right < left) {
		return std::make_pair(-1, -1);
	}
	if (x % 2 == 0) {
		if (right < x / 2) {
			return std::make_pair(-1, -1);
		}
	} else {
		if (right < x / 2 + 1) {
			return std::make_pair(-1, -1);
		}
	}

	ll r = right;
	ll l = left;

	if (r + l > x) {
		r -= r + l - x;
	} else {
		l += x - r + l;
	}
	
	if (r < l) {
		return std::make_pair(-1, -1);
	}	
	return std::make_pair(l, r);
}

std::pair<ll, ll> pick(ll x, ll a, ll b)
{
	if (a > b) {
		return std::make_pair(-1, -1);
	}
	if (x < a) { //fully out
		return try_from(x, 0, x);
	}

	if (x >= a && x <= b) {   ///in
		return try_from(x, 0, a - 1);
	}

	auto r = try_from(x, 0, a - 1);
	if (r.first == -1) {
		r = try_from(x, b + 1, x);
	}
	
	
	return r;
}

void solve(int tt)
{
	ll x, y;
	std::cin >> x >> y;

	for (int i = 1; i <= std::ceil(std::sqrt(y)); ++i) {
		
		if (y % i != 0) {
			continue;
		}
		auto r = pick(x, i, y / i);
		if (r.first == -1) {
			continue;
		}

		std::cout << r.first << " " << r.second << std::endl << i << " " << y / i << std::endl;
		return;
	}
	std::cout << -1 << std::endl;
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