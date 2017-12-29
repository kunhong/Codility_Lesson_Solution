#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    /*
    std::sort(A.begin(), A.end());
    
    auto it = A.begin();
    
    while (it != A.end()) {
        auto cnt = std::count(it, A.end(), *it);
        if(cnt % 2 != 0) return *it;
        it += cnt;
    }
     */
    
    // 짝이 맞지 않는 수 찾기
    std::unordered_set<int> us;
    
    for (auto a : A) {
        if (us.count(a)) {
            us.erase(a);
        }
        else {
            us.insert(a);
        }
    }
    
    return *us.begin();
}

int main()
{
    std::vector<int> v = {9,3,9,3,9,7,9};
    cout  << solution(v) << endl;
    return 0;
}

