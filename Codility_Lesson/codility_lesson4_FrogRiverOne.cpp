#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::set<int> mySec;
    int sum = X  *( X + 1) / 2;
    for (int i = 0; i < A.size(); ++i) {
        if (mySec.find(A[i]) == mySec.end()) {
            mySec.insert(A[i]);
            sum -= A[i];
        }
        if (0 == sum) return i;
        
    }
    return -1;
}

int main() {
    std::vector<int> vec = {1,3,1,4,2,3,5,4};
    
    cout << solution(5, vec) << endl;
    return 0;
}

