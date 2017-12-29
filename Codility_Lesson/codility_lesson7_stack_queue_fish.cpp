#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
/*
int solution(vector<int> &A, vector<int> &B) {
    
    std::stack<std::pair<int, int>> stk;
    for (int i = 0 ; i < A.size(); i++) {
        
        if (stk.empty() || (stk.top().second - B[i] < 0))
            stk.push(std::make_pair(A[i], B[i]));
        else {
            while(1) {
                if(stk.empty()) {
                    stk.push(std::make_pair(A[i], B[i]));
                    break;
                }
                else if (stk.top().first < A[i] && stk.top().second != B[i]) {
                    stk.pop();
                }
                else if (stk.top().second == B[i]) {
                    stk.push(std::make_pair(A[i], B[i]));
                    break;
                }
                else {
                    break;
                }
            }
        }
        

    }
    
    return stk.size();
    
}
*/
int solution(vector<int> &A, vector<int> &B) {
    int count = A.size();
    std::stack<int> upStraem;
    
    for (int i = 0; i < A.size(); i++) {
        if (B[i] == 1) {
            upStraem.push(A[i]);
        }
        else {
            while (upStraem.size() > 0) {
                count--;
                if (upStraem.top() > A[i]) {
                    break;
                }
                else {
                    upStraem.pop();
                }
            }
        }
    }
    
    
    return count;
}
/*
 public int solution(int[] A, int[] B) {
 var count = A.Length;
 
 var upStream = new Stack<int>();
 
 for(int i = 0, len = count; i < len; i++)
 {
 if(B[i] == 1)
 {
 upStream.Push(A[i]);
 }
 else
 {
 while(upStream.Count > 0)
 {
 count--;
 if(upStream.Peek() > A[i])
 {
 break;
 }
 else
 {
 upStream.Pop();
 }
 }
 }
 }
 
 return count;
 }
 */

int main(int argc, const char * argv[]) {
    vector<int> arr1 = {4,3,2,1,5};
    vector<int> arr2 = {0,1,0,0,0};
    //vector<int> arr1 = {1,2,3,4,5};
    //vector<int> arr2 = {1,1,1,1,0};
    cout << solution(arr1, arr2) << endl;
    return 0;
}
