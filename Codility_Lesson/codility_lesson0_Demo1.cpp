// you can use includes, for example
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
#include <numeric>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
        std::sort(A.begin(), A.end());
    A.erase(std::unique(A.begin(), A.end()), A.end());

    
    if (A.back() < 1 || A[0] > 1) return 1;
    
    for(int i = 0 ; i < A.size()-1; i++) {
        if (A[i] >= 0 && A[i+1] != A[i] + 1) return A[i] + 1;
    }
    
    return A[A.size() - 1] + 1;
}



int main()
{
    std::vector<int> arr {1, 2,3};
    cout << solution(arr) << endl;
    return 0;

}
