#include<iostream>
#include<vector>

using namespace std;

int countSubarraySums(int n, std::vector<int> arr) {
    int sum = 0;
    int count = 0;
    int j = 0;
    if (!arr.size()) return 0;  
    while (j < arr.size()) {
        for (int i = j; j < arr.size(); i++) {
            if (sum < n) {
                sum += arr[i];
            }
            else if (sum >= n) break;
        }
        if (sum == n) count++;
        sum = 0;
        j++;
    }
    return count;
}

int main() {
    //8,[9,8,9,7,5,5,1,4,8
    vector<int>arr = { 9, 8, 9, 7, 5, 5, 1, 4, 8 };
    int n = 8;
    cout << " the result " << countSubarraySums(n, arr);
    return 0;
}