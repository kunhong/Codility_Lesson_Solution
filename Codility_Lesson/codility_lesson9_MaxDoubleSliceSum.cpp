#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <numeric>
using namespace std;

// 배열의 부분합이 가장 큰 경우를 찾는 알고리즘

int solution(vector<int> &A) {
    int N = A.size();
    
    vector<int> K1(N, 0);
    vector<int> K2(N, 0);
    
    for (int i = 1; i < N-1; i++) {
        K1[i] = std::max(K1[i-1] + A[i], 0);
    }
    
    for (int i = N-2; i >0; i--) {
        K2[i] = std::max(K2[i+1] + A[i], 0);
    }
    
    
    int max = 0;
    
    
    for(int i = 1; i < N-1; i++){
        max = std::max(max, K1[i-1]+K2[i+1]);
    }
    return max;
}


/*
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    vector<int> from_begin(N); //MaxSliceSum of [1, i] containing A[i]
    vector<int> from_end(N); //MaxSliceSum of [N-1-i, N-2] containing A[N-1-i]
    
    from_begin[0] = 0;
    from_begin[1] = A[1];
    for (int i = 2; i < N-1; i++) {
        from_begin[i] = max (A[i], from_begin[i-1]+A[i]);
    }
    
    from_end[0] = 0;
    from_end[1] = A[N-1-1];
    for (int i = 2; i < N-1; i++) {
        from_end[i] = max(A[N-1-i], A[N-1-i]+from_end[i-1]);
    }
    
    int max_slice = 0;
    int curr = 0;
    for (int i = 1; i < N-1; i++) {
        curr = max(0, from_begin[i-1]) + max(0, from_end[N-1-(i+1)]);
        max_slice = max(curr, max_slice);
    }
    
    return max_slice;
}
 */

/*
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() <=3) return 0;
    
    int N = A.size() / 2;
    auto left_min = std::min_element(A.begin(), A.begin() + N);
    cout << std::distance(std::begin(A), left_min) << " : "<< *left_min << endl;
    
    auto right_min = std::min_element(A.begin() + N, A.end());
    cout << std::distance(std::begin(A)+N, right_min) << " : "<<  *right_min << endl;
    
    int left_dis = std::distance(std::begin(A), left_min);
    int right_dis = std::distance(std::begin(A)+N, right_min);
    
    
    int lef_sum = std::accumulate(A.begin()+1, A.begin() + left_dis, 0);
    int righ_sum = std::accumulate(A.begin() + left_dis + 1, A.begin() + left_dis + right_dis +  1, 0);
    return lef_sum + righ_sum;
    
    
}
*/
int main(int argc, const char * argv[]) {
    vector<int> v1 {4,3,3,3,4,2};
    vector<int> v2 {3,2,6,-1,4,5,-1,2};
    vector<int> v3 {6, 1, 5, 6, 4, 2, 9, 4};
    
    vector<int> v4 {-2, -3, -4, 1, -5, -6, -7};
    cout << solution(v2) << endl;
    return 0; // 6, 1, 5, 6, 4, 2, 9, 4]
}
