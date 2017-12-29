#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    if (A.empty()) return -1;
    
    std::unordered_map<int, int> umap;
    for (auto a : A) {
        if (umap.find(a) == umap.end()) {
            umap[a] = 1;
        }
        else {
            umap[a]++;;
        }
    }
    
    auto x = std::max_element(umap.begin(), umap.end(),
                              [](const pair<int, int>& p1, const pair<int, int>& p2) {
                                  return p1.second < p2.second; });
    
    if (x->second <= (A.size() / 2)) return -1;
    for (int i = 0; i < A.size(); i++) {
        if(x->first == A[i]) {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    //vector<int> v {4,3,3,3,4,2};
    vector<int> v {3,4,3,2,3,-1,3,3};
    //vector<int> v {0,0};
    cout << solution(v) << endl;
    return 0;
}

