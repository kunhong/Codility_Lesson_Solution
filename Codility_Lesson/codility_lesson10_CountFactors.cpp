#include <iostream>
using namespace  std;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    // 1..2,147,483,647
    
    int i = 1;
    int sum = 0;
    
    while ( i * i < N)
        if (0 == N % i++) sum += 2;
    
    if ( N == i * i) sum += 1;
    
    return sum;
}

int main() {
    cout << solution(24) << endl;
    return 0;
}


