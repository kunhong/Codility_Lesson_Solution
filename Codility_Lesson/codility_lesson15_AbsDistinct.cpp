#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
/*
 N is an integer within the range [1..100,000];
 K is an integer within the range [1..1,000,000,000];
 each element of array A is an integer within the range [1..1,000,000,000]
 */



int solution(vector<int> &A) {
    std::transform(A.begin(), A.end(), A.begin(), [](int a) {
        return abs(a);
    });
    
    std::sort(A.begin(), A.end());
    
    A.erase(std::unique(A.begin(), A.end()), A.end());
    
    return A.size();
}


int main() {
    vector<int> A = {-5,-3,-1,0,3,6};
    cout << solution(A) << endl;
    return 0;
}
