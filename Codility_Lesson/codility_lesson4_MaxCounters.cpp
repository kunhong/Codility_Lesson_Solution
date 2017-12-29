#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(int N, vector<int> &A) {
    std::vector<int> res(N, 0);
    
    int current_max = 0;
    int used_max = 0;
    for (auto a : A) {
        if (a >=1 && a <= N) {
            res[a-1] = std::max(used_max, res[a-1]) + 1;
            current_max = std::max(current_max, res[a-1]);
        }
        else {
            used_max = current_max;
        }
    }
    
    std::replace_if(res.begin(),res.end(), [&used_max](int i) {
        return i < used_max;
    }, used_max);
    
    return res;
}

int main() {
    std::vector<int> vec = {3,4,4,6,1,4,4};
    auto v_cnt = solution(5, vec);
    return 0;
}

/*
 For example, given integer N = 5 and array A such that:
 
 A[0] = 3
 A[1] = 4
 A[2] = 4
 A[3] = 6
 A[4] = 1
 A[5] = 4
 A[6] = 4
 the values of the counters after each consecutive operation will be:
 
 (0, 0, 1, 0, 0)
 (0, 0, 1, 1, 0)
 (0, 0, 1, 2, 0)
 (2, 2, 2, 2, 2)
 (3, 2, 2, 2, 2)
 (3, 2, 2, 3, 2)
 (3, 2, 2, 4, 2)
 */
