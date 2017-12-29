#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::sort(A.begin(), A.end());
    A.erase(std::unique(A.begin(), A.end()), A.end());
    return A.size();
}

int main()
{
    std::vector<int> vec = {2,1,1,2,3,1};
    cout << solution (vec) << endl;
    
    return 0;
}
