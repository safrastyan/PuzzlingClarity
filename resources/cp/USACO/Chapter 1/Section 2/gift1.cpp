/*
ID: safrast1
TASK: gift1
LANG: C++11          
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

int main() 
{
    std::ofstream fout ("gift1.out");
    std::ifstream fin ("gift1.in");
    std::map<std::string, int> bank;

    int n;
    fin >> n;
    std::vector<std::string> names(n);
    for (int i = 0; i < n; ++i) {
    	std::string name;
    	fin >> name;
    	names[i] = name;
    	bank[name] = 0;
    }

    for (int i = 0; i < n; ++i) {
    	std::string name;
    	fin >> name;
    	int m, num;
    	fin >> m >> num;
    	if (num == 0) {
    		continue;
    	}

    	bank[name] -= m;
    	bank[name] += m % num;
    	m /= num;
    	for (int j = 0; j < num; ++j) {
    		std::string fr_name;
    		fin >> fr_name;
    		bank[fr_name] += m;
    	}
    }

    for (const auto& n: names) {
    	fout << n << " " << bank[n] << std::endl;
    }
    return 0;
}