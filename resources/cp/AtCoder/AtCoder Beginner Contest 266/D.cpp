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


struct E
{
	E(): time(0), score(0), pos(-1) {}
	E(int t, int s, int p): time(t), score(s), pos(p) {}
	int time;
	long long score;
	int pos;
	bool valid() {
		return pos != -1;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	vc<vc<E>> dp(n + 1, std::vector<E>(5));
	
	dp[0][0] = E(0, 0, 0);

	for (int k = 1;  k <= n; ++k) {
		int t, x, a;
		std::cin >> t >> x>> a;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (!dp[k - 1][i].valid()) {
					continue;
				}
				int dist = std::abs(i - j);

				if (std::abs(dp[k - 1][i].time + dist) > t) {
					continue;
				}
				E cur = dp[k - 1][i];
				if (x == j && t - cur.time >= dist) {
					cur.score += a;
				}
				cur.time = t;
				if (cur.score >= dp[k][j].score) {
					dp[k][j] = cur;
				}
				dp[k][j].time = t;
				dp[k][j].pos = 0;
			}
		}

	}
	long long m = 0;
	for (int i = 0 ; i < 5; ++i) {
		m = std::max(m, dp.back()[i].score);
	}
	std::cout << m << std::endl;
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
