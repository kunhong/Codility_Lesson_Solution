#include <iostream>
#include <algorithm>
#include <vector>
#include  <map>
#include <set>

using namespace std;

// 혼자서 다시 풀어볼것 (어려움)

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int N = S.size();
    int M = Q.size();
    
    std::vector<int> A(N,0);
    std::vector<int> C(N,0);
    std::vector<int> G(N,0);
    std::vector<int> Result(M);
    
    if (S[0] == 'A') A[0] = 1;
    else if(S[0] == 'C') C[0] = 1;
    else if(S[0] == 'G') G[0] = 1;
    
    for(int i = 1; i < N; i++) {
        if (S[i] == 'A') A[i] += A[i-1]+1;
        else A[i] = A[i-1];
        
        if (S[i] == 'C') C[i] += C[i-1]+1;
        else C[i] = C[i-1];
        
        if (S[i] == 'G') G[i] += G[i-1]+1;
        else G[i] = G[i-1];
    }
    
    for(int i  = 0; i < M; i++) {
        if (A[Q[i]] > A[P[i] - 1])
            Result[i] = 1;
        else {
            if (C[Q[i]] > C[P[i] - 1])
                Result[i] = 2;
            else {
                if (G[Q[i]] > G[P[i] - 1])
                    Result[i] = 3;
                else
                    Result[i] = 4;
            }
        }
    }
    
    return Result;
}

int main()
{
    //std::string str = {"CAGCCTA"};
    //std::vector<int> p = {2,5,0};
    //std::vector<int> q = {4,5,6};
  
    //std::string str = {"A"};
    //std::vector<int> p = {0};
    //std::vector<int> q = {0};
    
    std::string str = {"AC"};
    std::vector<int> p = {0,0,1};
    std::vector<int> q = {0,1,1};
    // 1 1 2
    
    auto res = solution(str, p, q);

    return 0;
}
