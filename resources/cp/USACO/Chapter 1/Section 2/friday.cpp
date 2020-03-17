/*
ID: safrast1
TASK: friday
LANG: C++11          
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

static int lens[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

void next(int y, int m, int d, int wd, std::vector<int>& res, int n)
{
	if (y == 1900 + n -1 && m == 11 && d == 31) {
		return;
	}
	if (d == 13) {
		++res[wd];
	}
	d += 1;
	if (d > lens[m]) {
		if (!(m == 1 && d == 29 && is_leap(y))) {
			d = 1;
			++m;
		}
	}
	if (m > 11) {
		m = 0;
		++y;
	}
	++wd;
	if  (wd > 6) {
		wd = 0;
	}
	next(y, m, d, wd, res, n);
}

int main() 
{
    std::ofstream fout ("friday.out");
    std::ifstream fin ("friday.in");
    int n;
    fin >> n;
    int y = 1900;
    int m = 0;
    int d = 1;
    int wd = 0;
    std::vector<int> res(7, 0);
    next(y, m, d, 0, res, n);
    fout << res[5] <<  " " << res[6] << " "<< res[0] << " " << res[1] << " "<< res[2] << " " << res[3] << " " << res[4] << std::endl;
    return 0;
}