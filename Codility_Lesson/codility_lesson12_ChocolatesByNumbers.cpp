#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 유클리드 알고리즘
int gcd (int p, int q) {
    if (p % q == 0) return q;
    return gcd(q, p % q);
}

int solution(int N, int M) {
    // write your code in C++14 (g++ 6.2.0)
    return N / gcd(N, M);
}

int main() {
    cout << solution (10, 4) << endl;
    return 0;
}
