#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // write your code in C++14 (g++ 6.2.0)
    map<int, int> planks_map;
    
    for (int i = 0; i < A.size(); ++i) {
        planks_map.insert(std::make_pair(A[i], B[i]));
    }
    
    for(auto c : C) {
        
    }
    
    return 0;
}

int main()
{
    vector<int> A = {1, 4, 5, 8};
    vector<int> B = {4, 5, 9, 10};
    vector<int> C = {4, 6, 7, 10, 2};
    cout << solution(A, B, C);
    return 0;
}
