#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty() || A.size() < 3) return 0;
    std::sort(A.begin(), A.end(), std::greater<int>());
    size_t len = A.size();
    return std::max(A[0]*A[1]*A[2], A[0] * A[len-1] * A[len-2]);
}

int main(int argc, const char * argv[]) {
    vector<int> arr = {-3,1,2,-2,5,6};
    cout << solution(arr) << endl;
    return 0;
}

