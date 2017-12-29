#include<iostream>
using namespace std;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    
    if (1 == N) return 4;
    
    int i  = 2;
    int perimeter = 2*(1+ N);
    
    while ( i * i < N) {
        if (0 == N % i) {
            perimeter = std::min(perimeter, (2*(i + (N/i))));
        }
        ++i;
    }
    
    if (N == i * i) {
        perimeter = std::min(perimeter, (2*(i + (N/i))));
    }
    
    return perimeter;
}


int main() {
    
    cout << solution(30) << endl;
    return 0;
}
