#include <iostream>
#include <vector>

using namespace std;


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = static_cast<int>(A.size());
    if (N < 3) return 0;
    
    std::sort(A.begin(), A.end());
    
    int triangle_cnt = 0;
    int P_index = 0;
    int Q_index = 0;
    int R_index = 0;
    
    for (P_index = 0; P_index < N -2; P_index++) {
        Q_index = P_index + 1;
        R_index = P_index + 2;
        while (R_index < N) {
            if (A[P_index] + A[Q_index] > A[R_index]) {
                triangle_cnt += (R_index - Q_index);
                R_index++;
            }
            else if (Q_index < R_index -1) {
                Q_index++;
            }
            else {
                R_index++;
                Q_index++;
            }
        }

    }
    
    
    return triangle_cnt;
}

int main()
{
    std::vector<int> A = {10, 2, 5, 1, 8, 12}; // 4
    std::vector<int> A2 = {3, 3, 5, 6}; // 3
    cout << solution(A2) << endl;
    return 0;
}
