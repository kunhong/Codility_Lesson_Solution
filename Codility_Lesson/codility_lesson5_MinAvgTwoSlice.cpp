#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::pair<int, int> min_pair = std::make_pair(0, A[0] + A[1]);
    
    for (int i = 1; i < A.size()-1; ++i) {
        if (min_pair.second > A[i] + A[i+1]) {
            min_pair.first = i;
            min_pair.second = A[i] + A[i+1];
        }
    }
    
    std::pair<int, int> min_pair_t = std::make_pair(0, A[0] + A[1] + A[2]);
    
    for (int i = 1; i < A.size()-2; ++i) {
        if (min_pair_t.second > A[i] + A[i+1] + A[i+2]) {
            min_pair_t.first = i;
            min_pair_t.second = A[i] + A[i+1] + A[i+2];
        }
    }
    
    double left_avg = static_cast<double>(min_pair.second)/2;
    double right_avg = static_cast<double>(min_pair_t.second)/3;
    
    if(left_avg == right_avg)
        return std::min(min_pair.first, min_pair_t.first);
    
    return left_avg < right_avg ? min_pair.first : min_pair_t.first;
    
}


int main() {
    std::vector<int> vec = {4,2,2,5,1,5,8};
    cout << solution(vec) << endl;
    return 0;
}

