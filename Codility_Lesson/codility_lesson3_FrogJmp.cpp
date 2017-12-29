#include <iostream>
#include <math.h>
using namespace std;

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    return static_cast<int>(ceil(static_cast<double>((Y-X))/D));
}

int main()
{
    cout << solution(10, 85, 30) << endl;;
    
    
    return 0;
}
