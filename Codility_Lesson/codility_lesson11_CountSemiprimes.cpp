#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    /*
    vector<int> vec;
    int max_element = *std::max(std::max_element(P.begin(), P.end()), std::max_element(Q.begin(), Q.end()));
    
    if(max_element > N) return vec;
    
    // 2  3  5   7  11  13
    // 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.
    vector<int> primes = {2,3};
    vector<int> semiprimes;
    
    int k = 1;
    int i = 1;
    while ((i = 6*k - 1) <= max_element/2) {
        primes.push_back(i);
        primes.push_back(i+2);
        k++;
    }
    
    for (i= 0; i < primes.size() && sqrt(primes[i]) <= max_element; i++) {
        for (int j = i; j < primes.size(); j++) {
            int m = primes[i] * primes[j];
            if (m > max_element) break;
            semiprimes.push_back(primes[i] * primes[j]);
        }
    }
    
    std::sort(semiprimes.begin(), semiprimes.end());
    
    for (i = 0; i < P.size(); i++) {
        int p = P[i];
        int q = Q[i];
        int cnt = std::count_if(semiprimes.begin(), semiprimes.end(),[=] (int a){
            return (a >=p && a<=q);
        });
        vec.push_back(cnt);
    }

    return vec;
     */
    

    std::vector<int> sieve (N + 1, 0);
    std::vector<int> sieve_cnt (N + 1, 0);
    int p_len = P.size();
    
    int i = 2;
    int k = 0;
    int cnt = 0;
    
    while ((k = i * i) <= N) {
        while (k <= N) {
            if(!sieve[k]) sieve[k] = i;
            k += i;
        }
        ++i;
    }
    
    for(i = 0; i < N + 1; ++i) {
        if(sieve[i] && 0 == sieve[i / sieve[i]]) ++cnt;
        sieve_cnt[i] = cnt;
    }
    
    std::vector<int> res (p_len, 0);
    
    for(i = 0; i < p_len; ++i) {
        res[i] = sieve_cnt[Q[i]] - sieve_cnt[P[i] - 1];
    }
    return res;
}

int main()
{

    //int N = 26;
    //vector<int> v1 = {1,4,16};
    //vector<int> v2 = {26,10,20};

    int N = 10;
    vector<int> v1 = {5};
    vector<int> v2 = {10};
    
    auto r = solution(N, v1, v2);
    return 0;
}

