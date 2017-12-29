
#include <iostream>
#include <vector>


using namespace std;

 bool divisionSolvable(int mid, int k, std::vector<int>& a) {
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        if (sum > mid) {
            sum = a[i];
            k--;
        }
        if (k == 0) {
            return false;
        }
    }
    return true;
}

int solution(int K, int M, std::vector<int>& A)
{
    int min = 0;
    int max = 0;
    for (int i = 0; i < A.size(); i++) {//get the sum as max, and the largest number as min
        max += A[i];
        min = std::max(min, A[i]);
    }
    int result = max;
    while (min <= max) {
        int mid = (min + max) / 2;
        if (divisionSolvable(mid, K, A)) {
            max = mid - 1;
            result = mid;
        } else {
            min = mid + 1;
        }
    }
    return result;
}

int main()
{
    std::vector<int> vec = {1,5,1,1,1,1};
    cout << solution(2, 5, vec) << endl;
    return 0;
}

