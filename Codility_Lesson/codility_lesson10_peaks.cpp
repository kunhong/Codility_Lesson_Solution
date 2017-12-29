#include <iostream>
#include <vector>
using namespace std;

// 81 % 솔루션 // Correctness : 100%. Performance : 60%
int solution2(vector<int> &A) {
    if (A.size() < 2) return 0;
    
    std::vector<bool> peaks(A.size(), false);
    
    int cnt = 0;
    
    
    for (int i = 1; i < A.size() -1; i++) {
        if (A[i-1] < A[i] && A[i+1] < A[i]) {
        peaks[i] = true;
        cnt++;
        }
    }
    
    if (cnt == 0) return 0;
    
    
    while (cnt) {
        int devide = A.size() / cnt;
        bool bFind = true;
        if (A.size() % devide != 0) {
            cnt--;
            continue;
        }
        
        
        
        for (std::vector<bool>::iterator it = peaks.begin(); it != peaks.end(); it += devide) {
            if (std::count(it, it + devide, true) == 0)  {
                bFind = false;
                break;
            }
        }
        

        
        if(bFind) return cnt;
        cnt--;
 
    }
    
    return 0;
}

// 100%
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    // find peaks
    vector<int> A_peaks(A.size());
    A_peaks[0] = 0;
    int cur_val = 0;
    for (size_t idx = 1; idx < A.size() - 1; ++idx)
    {
        if (A[idx] > A[idx-1] && A[idx] > A[idx+1])
            cur_val++;
        A_peaks[idx] = cur_val;
    }
    A_peaks[A.size() - 1] = cur_val;
    
    // Find solution
    int ret_val = 0;
    for (size_t blocks = 1; blocks <= A.size() / 2; ++blocks)
    {
        if (A.size() % blocks != 0)
            continue;
        size_t block_size = A.size() / blocks;
        
        int prev_peaks = 0;
        size_t idx = block_size;
        for (; idx < A.size() + block_size; idx += block_size)
        {
            if (A_peaks[idx - 1] == prev_peaks)
                break;
            prev_peaks = A_peaks[idx - 1];
        }
        
        if (idx == A.size() + block_size)
            ret_val = static_cast<int>(blocks);
    }
    
    return ret_val;
    /*
    
    int N = A.size();
    if (N < 3) return 0;
    
    std::vector<int> peaks;
    
    int i = 1;
    while ( i < N - 1) {
        if (A[i-1] < A[i] && A[i] > A[i+1]) {
            peaks.push_back(i);
            i += 2;
        }
        else {
            i++;
        }
    }
    
    int peak_size = peaks.size();
    
    if (peak_size == 0) return 0;
    

    int max_blocks = 1;
    
    while (peak_size > 1) {
        int j = 0;
        if (A.size() % peak_size != 0){
            peak_size--;
            continue;
        }
        int index = A.size() / peak_size;
        
        bool ispeak = true;
        for (int j = 0; j < N; j += index) {
            int n = std::count_if(A.begin() +j, A.begin() + j+index, [&peaks](int a) {
                return std::any_of(peaks.begin(), peaks.end(), [&a](int b) {
                    return a == b;
                });
            });
            
            if (n < 1) {
                ispeak = false;
                break;
            }
            
            cout << j << " ~ " << j+ index -1 << " : " << n << endl;
        }
        
        if(ispeak) ++max_blocks;

        peak_size--;
    }
    
    

    return max_blocks;
     */
}


int main() {
    std::vector<int> v = {1,2,3,4,3,4,1,2,3,4,6,2};
    std::vector<int> v2 = {0,1,0,0,1,0,0,1,0};
    std::vector<int> v3 = {1,3,2,1}; // 1
    cout << solution(v) << endl;

}


