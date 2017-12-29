#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 80%
/*
int solution(int M, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int N = static_cast<int>(A.size());
    int the_sum = 0;
    int front = 0;
    int back = 0;
    vector<bool> seen(M+1, false);
    
    while (front < N && back < N) {
        while (front < N && seen[A[front]] != true) {
            the_sum += (front-back+1);
            seen[A[front]] = true;
            front += 1;
        }
        
        while (front < N && back < N && A[back] != A[front]) {
            seen[A[back]] = false;
            back +=1;
        }
        
        seen[A[back]] = false;
        back +=1;
    }
    
    return min(the_sum, 1000000000);
    
}
 */

// 30%
int solution(int M, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int N = A.size();
    
    int front = 0;
    int back = 0;
    int sum = 0;
    
    std::vector<bool> checker(M+1, false);
    
    while (front < N && back < N) {
        while (front < N && checker[A[front]] == false) {
            checker[A[front]] = true;
            sum += (front++ - back + 1);
        }
        
        while (front < N && back < N && A[front] != A[back]) {
            checker[A[back++]] = false;
        }
        
        checker[A[back++]] = false;
    }
    return min(sum, 1000000000);
    
}

// (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4)

int main() {
    vector<int> A = {3,4,5,5,2};
    cout << solution(6, A) << endl;
    return 0;
}
