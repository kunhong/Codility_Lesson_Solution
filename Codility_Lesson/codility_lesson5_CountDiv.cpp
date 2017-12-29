#include <iostream>
#include <vector>

using namespace std;


int solution(int A, int B, int K) {
    
    return (A % K == 0) ? (B / K) - (A / K) + 1 : (B / K) - (A / K);
}

int main() {
    cout << solution(6, 9, 3) << endl;
    return 0;
}

// A = 6, B = 11 and K = 2,
