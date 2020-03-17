/*
ID: safrast1
TASK: ride
LANG: C++11          
*/

#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    std::ofstream fout ("ride.out");
    std::ifstream fin ("ride.in");
    std::string a,b;
    fin >> a >> b;
    long long r1 = 1, r2 = 1;
    
    for (char c : a) {
    	r1 *= static_cast<int>(c - 'A' + 1);
    }

    for (char c : b) {
    	r2 *= static_cast<int>(c - 'A' + 1);
    }
    fout << (r1 % 47 == r2 % 47 ? "GO" : "STAY") << std::endl;
    return 0;
}