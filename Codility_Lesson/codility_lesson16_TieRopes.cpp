#include <iostream>
#include <vector>

using namespace std;
/*
 N is an integer within the range [1..100,000];
 K is an integer within the range [1..1,000,000,000];
 each element of array A is an integer within the range [1..1,000,000,000]
 */



int solution(int K, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0, current = 0;
    for (auto a : A) {
        current += a;
        if (current >= K) {
            cnt++;
            current = 0;
        }
    }

    return cnt;
}


int main() {
    vector<int> A = {1,2,3,4,1,1,3};
    cout << solution(4, A) << endl;
    return 0;
}
