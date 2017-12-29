#include <iostream>
#include <algorithm>
#include <vector>

#include <numeric>
using namespace std;
int solution(vector<int> &A) {

    std::sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); ++i)
        if ((i + 1) != A[i]) return 0;
    
    return 1;
}

int main() {
    std::vector<int> vec0 = {4,1,3,2};
    std::vector<int> vec1 = {9,5,7,3,2,7,3,1,10,8};
    cout << solution(vec0) << endl;
    cout << solution(vec1) << endl;
    return 0;
}
