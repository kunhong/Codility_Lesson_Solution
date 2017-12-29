#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    if (N < 3) return 0;
    vector<int> peaks;
    
    for (int i = 1; i < N -1; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) peaks.emplace_back(i);
    }
    
    for (int size = 1; size <= N; size++) {
        if (N % size != 0)
            continue;
        
        int find = 0;
        int groups = N/size;
        
        for (auto peakIdx : peaks) {
            if (peakIdx/size >  find) {
                break;
            }
            
            if (peakIdx/size == find)
                find++;
        }
        
        if (find == groups)
            return groups;
        

        
    }

    
    return 0;
}

int main() {
    vector<int>  A = {1,5,3,4,3,4,1,2,3,4,6,2};
    //vector<int>  A = {1,2,1,2,1,2,1,2,1,2,1};
    cout << solution(A) << endl;
    return 0;
}

