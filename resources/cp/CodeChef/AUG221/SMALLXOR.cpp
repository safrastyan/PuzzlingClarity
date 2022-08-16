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
	int n, x, y;
	std::cin >> n >> x >> y;
	auto a = readai(n);

	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	for (auto aa: a) {
		q.push(aa);
	}

	for (int i = 1; i <= y; ++i) {
		auto elem = q.top();
		q.pop();
		auto nn = elem ^ x;
		q.push(nn);
		if (nn > elem) {
			continue;
		}

		if ( (y - i) % 2 == 0) {
			break;
		}
		elem = q.top();
		q.pop();
		q.push(elem ^ x);
		break;
	}

	while (!q.empty()) {
		std::cout << q.top() << " ";
		q.pop();
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
