#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    
    int cnt = 0;
    
    for (int i = 0; i < N-1; i++) {
        long long curl = (long long)i - A[i];
        long long curr = (long long)i + A[i];
        
        for (int j = i + 1; j < N; j++){
            long long posl = (long long)j - A[j];
            long long posr = (long long)j + A[j];
            
            if (posl <= curr && curl <= posr){
                cnt++;
                if (cnt > 10000000){
                    return -1;
                }
            }
        }
    }
    return cnt;
}

int main() {
    std::vector<int> vec = {1,5,2,1,4,0};
    cout << solution(vec) << endl;
    return 0;
}
