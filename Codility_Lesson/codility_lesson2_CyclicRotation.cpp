#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;

// 배열을 index 만큼 옮기기 (순환 배열)
vector<int> solution(vector<int> &A, int K) {
    if (A.empty()) return A;
    int N = K % A.size();
    
    std::rotate(A.begin(), A.begin() + (A.size() - N), A.end());
    return A;
}
/*
vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)

    if (A.empty()) return A;
    int N = K % A.size();
    
    std::vector<int> ret;
    ret.reserve(A.size());
    std::copy(A.end() - N, A.end(),  std::back_inserter(ret));
    std::copy(A.begin(), A.end() - N,  std::back_inserter(ret));
    
    
    return ret;
}
*/
int main() {
    std::vector<int> arr = {3,8,9,7,6};
    auto v= solution(arr, 2);
    //std::vector<int> arr2 = {5, -1000};
    
    //auto v= solution(arr, 1);
    
    for (auto a : v)
        cout << a << " ";
    
    cout << endl;
    return 0;
}
