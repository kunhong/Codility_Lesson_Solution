#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> &H) {
    int cnt = 0;
    stack<int> bricks;
    
    for (auto h : H) {
        
        while (!bricks.empty() && bricks.top() > h) {
            bricks.pop();
        }
        
        if (bricks.empty() || bricks.top() < h) {
            bricks.push(h);
            ++cnt;
        }
    }
    
    return cnt;
}


int main(int argc, const char * argv[]) {
    vector<int> arr = {8,8,5,7,9,8,7,4,8};
    cout << solution(arr) << endl;
    return 0;
}



/*
 
 int solution(vector<int> &H) {
 stack<int> bricks;
 int count = 0;
 
 for (auto br : H) {
 
 while (!bricks.empty() && bricks.top() > br) {
 bricks.pop();
 }
 
 if (bricks.empty() || bricks.top() < br) {
 bricks.push(br);
 ++count;
 }
 
 }
 
 return count;
 }
 */
