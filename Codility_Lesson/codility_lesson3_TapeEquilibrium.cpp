#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() < 2) return 0;
    int sum = std::accumulate(A.begin()+1, A.end(), 0);
    int left = A[0];
    int min = std::abs(left - sum);

    for (int i = 1; i < A.size()-1; i++)
    {
        left += A[i];
        sum -= A[i];
        min = std::min(min, std::abs(left-sum));
    }
    
    return min;
}

int main()
{
    std::vector<int> v = {-1000, 1000};
    cout << solution(v) << endl;
    return 0;
}
