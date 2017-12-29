#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <numeric>
using namespace std;


// 배열의 구간 내 가장 합을 찾아내는 문제

int solution(vector<int> &A) {
    
    if (A.size() < 1) return 0;
    else if (A.size() == 1) return A[0];
    int max_ending = - 1000000;
    int max_slice = - 1000000;
    
    for (auto a: A) {
        max_ending = std::max(a, max_ending + a);
        max_slice = std::max(max_slice, max_ending);
        
    }

    return max_slice;
}


int main(int argc, const char * argv[]) {

    vector<int> v {-2,-2};
    vector<int> v2 {3,2,-1,6,1,-3}; // return 11
    vector<int> v3 {5,-7,3,5,-2,4,-1};

    cout << solution(v3) << endl;
    return 0;
}


