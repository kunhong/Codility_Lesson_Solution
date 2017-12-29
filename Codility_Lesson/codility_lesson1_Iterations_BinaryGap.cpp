#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

/*
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    std::string bit_str = std::bitset<32>(N).to_string();
    auto start_it = std::find(bit_str.begin(), bit_str.end(), '1');
    if(start_it == bit_str.end()) return 0;
    
    int max_gap = 0;
    
    while(start_it != bit_str.end()) {
        start_it++;
        auto second_it = std::find(start_it, bit_str.end(), '1');
        //max = std::max(max, std::distance(start_it, second_it));
        if (second_it != bit_str.end()) {
            int i = std::distance(start_it, second_it);
            max_gap = std::max(max_gap, i);
        }
        
        start_it = second_it;
    }
    

    return max_gap;
}
*/

// 10진수를 2진수로 바꾸고 1 사이의 0의 가장 큰 개수 찾기
int solution(int N) {
    int maxcount = 0;
    int count = 0;
    bool flag = false;
    /*
    string str;
    for (int i = 0; i < 32; i++) {
        str = ((N >> i) & int(1) ? '1' : '0') + str;
    }
    
    cout << str << endl;
     */
    for (int i = 0; i < 32; i++) {
        bool bit = (N >> i) & (int)1;
        if(bit) {
            flag = true;
            if (count < maxcount)
                maxcount = count;
            count = 0;
        }
        else
            if (flag)
                count++;
    }
    
    return maxcount;
}

/*
 For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.
 */
int main() {
    cout << solution(1041) << endl;
    return 0;
}
