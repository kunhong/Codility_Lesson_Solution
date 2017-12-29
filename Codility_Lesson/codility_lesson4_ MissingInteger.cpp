#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty()) return 1;
    std::set<int> a_set (A.begin(), A.end());
    
    int idx = 1;
    for(auto a : a_set) {
        if (a > 0) {
            if(a != idx) return idx;
            ++idx;
        }
    }
    
    return idx;
}

int main() {
    std::vector<int> vec0 = {4,5,6,2}; // 1
    std::vector<int> vec1 = {1,3,6,4,1,2};
    std::vector<int> vec2 = {1,2,3};
    std::vector<int> vec3 = {-1,-2};
    std::vector<int> vec4 = {4,5,5,6,8,8,9,9,1,2,2,3,3,3};
    std::vector<int> vec5 = {2};
    cout << solution(vec0) << endl;
    cout << solution(vec1) << endl;
    cout << solution(vec2) << endl;
    cout << solution(vec3) << endl;
    cout << solution(vec4) << endl;
    cout << solution(vec5) << endl;

    return 0;
}
