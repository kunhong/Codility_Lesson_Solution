#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<int> &A) {
    
    auto find_it = std::find(A.begin(), A.end(), 0);
    if (find_it == A.end()) return 0;
    int sum = std::accumulate(find_it, A.end(), 0);
    int cnt = sum;
    for(auto it = find_it + 1; it != A.end(); it++) {
        if (cnt == 0)break;
        if(*it == 1) sum--;
        else if(*it == 0) cnt += sum;
        if (cnt > 1000000000) return -1;
    }
    
    return cnt;
}


int main()
{
    std::vector<int> vec = {0,1,0,1,1};
    std::vector<int> vec2 = {1,0};
    cout << solution(vec) << endl;
    cout << solution(vec2) << endl;
    return 0;
}
