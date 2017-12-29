#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> &A) {
    /* 모두 틀림
    // write your code in C++14 (g++ 6.2.0)
    auto asInt = std::minmax_element(A.begin(), A.end());
    int sum = std::accumulate(A.begin(), A.end(), 0);
    
    for (int i = *asInt.first; i <= *asInt.second; i++)
        sum -= i;
    
    return std::abs(sum);
    */
    
    /* performance가 80%
    int size_A = A.size();
    int sum = (size_A + 1) * (size_A + 2) / 2;
    int sum_a = std::accumulate(A.begin(), A.end(), 0);
    
    return sum - sum_a;
     */
    
    int sum = A.size() + 1;
    for (int i = 0; i < A.size(); i++) {
        sum += (i + 1) - A[i];
    }
    
    return sum;

}

int main(){
    std::vector<int> arr = {2,3,1,5};
    cout << solution(arr) << endl;
    return 0;
}
