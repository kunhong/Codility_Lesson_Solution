#include <iostream>
#include <vector>
#include <map>

using namespace std;

// original
int solution(vector<int> &A, vector<int> &B) {
    size_t N = A.size();
    if (N < 2) return static_cast<int>(N);
    
    int count = 1;
    int end = B[0];
    int index = 1;
    
    while (index < N) {
        while (index < N && A[index] <=end)
            index++;
        if (index == N) break;
        count++;
        end = B[index];
    }
    
    return count;
}


int main()
{
    //vector<int> A = { 1 ,3, 7, 9, 9};
    //vector<int> B = { 5, 6, 8, 9, 10};
    
    vector<int> A = { 1, 2};
    vector<int> B = { 2, 3}; // return 3
    
    cout << solution (A, B) << endl;
    
    
    return 0;
}


