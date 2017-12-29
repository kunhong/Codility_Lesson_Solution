#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    int size = 0;
    int candidate = -1;
    int result = 0;
    
    for (int i = 0; i < len; i++) {

        
        if (0 == size) {
            candidate = A[i];
            size++;
        }
        else {
            if (A[i] != candidate)
                --size;
            else
                ++size;
        }
    }
    
    if (size < 1) return 0;
    
    int count = 0;
    std::vector<int> p1;
    for (int i = 0; i < len; i++) {
        if (candidate == A[i]) {
            ++count;
        }
        p1.push_back(count);
    }
    
    if (count <= len/2) return 0;
    
    for (int i = 0; i < len; i++) {
        if ((p1[i] > (i+1)/2) && (count - p1[i] > (len - 1 - i)/2))
            result++;
    }
    
 return result;
    
}

int main(int argc, const char * argv[]) {
    //vector<int> v {4,3,3,3,4,2};
    vector<int> v {4,3,4,4,4,2};
    //vector<int> v {0,0};
    cout << solution(v) << endl;
    return 0;
}

