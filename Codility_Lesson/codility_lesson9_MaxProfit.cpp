#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <numeric>
using namespace std;

// 배열 구간내 가장 이익이 가장 많이 나는 값을 찾기 (Maxium Slice)

/*
 A[0] = 23171
 A[1] = 21011
 A[2] = 21123
 A[3] = 21366
 A[4] = 21013
 A[5] = 21367
 the function should return 356, as explained above.
 
 Assume that:
 
 N is an integer within the range [0..400,000];
 each element of array A is an integer within the range [0..200,000].

 */
int solution(vector<int> &A) {
    int N = A.size();
    
    if (N == 0) return 0;
    if (N == 1) return A[0] > 0 ? A[0] : 0;
    
    int minBuying = A[0];
    int maxProfit = 0;
    
    for (std::vector<int>::iterator it = A.begin() + 1; it != A.end(); it++) {
        maxProfit = std::max(maxProfit, *it - minBuying);
        minBuying = std::min(*it, minBuying);
    }
    
    return maxProfit;
}

int solution_original(vector<int> &A) {
    if (A.size() <= 1) return 0;
    
    int minBuyingPrice = A[0];
    int maxProfitSoFar = 0;
    
    for (int i = 1; i < A.size(); i++) {
        maxProfitSoFar = std::max(maxProfitSoFar, A[i] - minBuyingPrice);
        minBuyingPrice = std::min(minBuyingPrice, A[i]);
    }
    
    return maxProfitSoFar;

    /*
    size_t N = A.size();
    
    vector<int> arr1 (N, 0);
    
    int max_index = 0;
    int max_value = 0;
    for (int i = 1; i < N ; i++) {
        arr1[i] = A[i] - A[i-1];
        if (arr1[i] >= max_value) {
            max_index = i;
            max_value = arr1[i];
        }
        
    }

    for (int i = max_index; i > 0; i--) {
        max_value = std::max(max_value, A[max_index] - A[i-1]);
    }

    return max_value;
     */
    
}



int main(int argc, const char * argv[]) {
    vector<int> v1 {23171,21011,21123,21366,21013,21367}; // 356
    vector<int> v2 {2,2,1,3,10,3};
    vector<int> v3 {8, 9, 3, 6, 1, 2}; // 3
    vector<int> v4 {1,2,3,4,5};
    vector<int> v5 {1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6};

    cout << solution(v5) << endl;
    return 0; // 6, 1, 5, 6, 4, 2, 9, 4]
}
