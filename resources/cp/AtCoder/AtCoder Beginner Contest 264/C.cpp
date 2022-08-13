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


vc<vc<int>> extr(const vc<vc<int>>& a, const vc<int>& row_mask, const vc<int>& col_mask)
{
	vc<vc<int>> res;
	for (int i = 0; i < a.size(); ++i) {
		if (row_mask[i] == 1) {
			continue;
		}
		res.push_back(vc<int>());
		for (int j = 0; j < a[0].size(); ++j) {
			if (col_mask[j] == 0) {
				res.back().push_back(a[i][j]);
			}
		}
	}
	return res;
}

bool same(const vc<vc<int>>& a, const vc<vc<int>>& b)
{
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].size(); ++j) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool ch(const vc<vc<int>>& a, const vc<int>& row_mask, const vc<int>& col_mask, const vc<vc<int>>& b)
{
	int row_d = a.size() - b.size();
	int col_d = a[0].size() - b[0].size();

	int rd = std::count(row_mask.begin(), row_mask.end(), 1);
	int cd = std::count(col_mask.begin(), col_mask.end(), 1);
	if (row_d != rd || col_d != cd) {
		return false;
	}

	auto r = extr(a, row_mask, col_mask);
	return same(r, b);

}

void fill_mask(int i, int total, vc<int>& r, vc<int>& c, int rows)
{
	int pos = 0;
	r = vc<int>(rows, 0);
	c = vc<int>(total - rows, 0);
	vc<int>* cur = &r;
	while (i != 0) {
		(*cur)[pos] = i % 2;
		i /= 2;
		++pos;
		if (pos == cur->size()) {
			pos = 0;
			cur = &c;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n1, m1, n2, m2;
	std::cin >> n1 >> m1;
	vc<vc<int>> a(n1, vc<int>(m1));


	for (int i =0 ; i < n1; ++i) {
		for (int j = 0 ; j < m1; ++j) {
			std::cin >> a[i][j];
		}
	}
	std::cin >> n2 >> m2;
	vc<vc<int>> b(n2, vc<int>(m2));
	
	for (int i =0 ; i < n2; ++i) {
		for (int j = 0 ; j < m2; ++j) {
			std::cin >> b[i][j];
		}
	}


	vc<int> row_mask, col_mask;

	row_mask.reserve(n1);
	col_mask.reserve(m1);
	int total = n1 + m1;

	for (int i = 0; i <= (1 << total) - 1; ++i) {
		fill_mask(i, total, row_mask, col_mask, n1);
		if (ch(a, row_mask, col_mask, b)) {
			std::cout << "Yes" << std::endl;
			return 0;
		}
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
