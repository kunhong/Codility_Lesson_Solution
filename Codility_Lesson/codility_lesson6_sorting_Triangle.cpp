#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/*
bool checkIntRage(const int& a) {
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();
    //N is an integer within the range [0..100,000];
    //each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
    if (max <= a && min >= a)
        return true;
    
    return false;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::sort(A.begin(), A.end());
    
    if (A.empty() || A.size() < 3 || A.size() > 100000) return 0;
    

    for (int i = 0; i < A.size() - 2; i++) {
        if (!checkIntRage(A[i]) || !checkIntRage(A[i+1] || !checkIntRage(A[i+2]))) continue;
        if (A[i] + A[i+1] > A[i+2]) return 1;
    }
    return 0;
}
*/
int solution(vector<int> &A) {
    
    
    std::sort(A.begin(), A.end());
    int N = static_cast<int>(A.size());
    
    if (N < 3 || N > 100000) return 0;

    for (int P_idx = 0; P_idx < N-2; P_idx++) {
        if (A[P_idx] + A[P_idx+1] > A[P_idx+2]) {
            return 1;
        }
    }

    return 0;
}


int main(int argc, const char * argv[]) {
    vector<int> arr = {10,2,5,1,8,20};
    cout << solution(arr) << endl;
    return 0;
}


