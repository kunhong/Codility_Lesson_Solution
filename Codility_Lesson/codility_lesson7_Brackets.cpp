#include <iostream>
#include <stack>

using namespace std;



int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    std::stack<char> stk;
    for (auto s : S)
    {
        if (s == '[' || s == '{' || s == '(')
            stk.push(s);
        else {
            if (s == stk.top()) {
                stk.pop();
            }
            else {
                return -1;
            }
        }
            
    }
    return 1;
}

int main()
{
    std::string S = "{[()()]}";
    cout << solution(S) << endl;
    return 0;
}
