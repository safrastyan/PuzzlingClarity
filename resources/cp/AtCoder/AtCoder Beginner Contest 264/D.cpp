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

	std::string s;
	std::string target = "atcoder";

	std::cin >> s;

	std::unordered_set<std::string> mark;
	
	std::queue<std::pair<std::string, int>> q;

	q.push(std::make_pair(s, 0));
	mark.insert(s);
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		auto ss = t.first;

		int dist = t.second;
		
		if (ss == target) {
			std::cout << dist << std::endl;
			return 0;
		}
		
		for (int i = 0; i < ss.size() - 1; ++i) {
			auto cur = ss;
			std::swap(cur[i], cur[i + 1]);
			if (mark.find(cur) == mark.end()) {
				mark.insert(cur);
				q.push(std::make_pair(cur, dist + 1));
			}
		}

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
