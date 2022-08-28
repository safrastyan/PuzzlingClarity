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
using namespace std;

int CrossProduct(vector<vector<int> >& A)
{
    // Stores coefficient of X
    // direction of vector A[1]A[0]
    int X1 = (A[1][0] - A[0][0]);
 
    // Stores coefficient of Y
    // direction of vector A[1]A[0]
    int Y1 = (A[1][1] - A[0][1]);
 
    // Stores coefficient of X
    // direction of vector A[2]A[0]
    int X2 = (A[2][0] - A[0][0]);
 
    // Stores coefficient of Y
    // direction of vector A[2]A[0]
    int Y2 = (A[2][1] - A[0][1]);
 
    // Return cross product
    return (X1 * Y2 - Y1 * X2);
}
 
// Function to check if the polygon is
// convex polygon or not
bool isConvex(vector<vector<int> >& points)
{
    // Stores count of
    // edges in polygon
    int N = points.size();
 
    // Stores direction of cross product
    // of previous traversed edges
    int prev = 0;
 
    // Stores direction of cross product
    // of current traversed edges
    int curr = 0;
 
    // Traverse the array
    for (int i = 0; i < N; i++) {
 
        // Stores three adjacent edges
        // of the polygon
        vector<vector<int> > temp
            = { points[i],
                points[(i + 1) % N],
                points[(i + 2) % N] };
 
        // Update curr
        curr = CrossProduct(temp);
 
        // If curr is not equal to 0
        if (curr != 0) {
 
            // If direction of cross product of
            // all adjacent edges are not same
            if (curr * prev < 0) {
                return false;
            }
            else {
                // Update curr
                prev = curr;
            }
        }
    }
    return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::vector<std::vector<int>> p(4);
	for (int i = 0; i < 4; ++i) {
		int x, y;
		std::cin >> x >> y;
		p[i].push_back(x);
		p[i].push_back(y);
	}
	std::cout << (isConvex(p) ? "Yes" : "No") << std::endl;
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
