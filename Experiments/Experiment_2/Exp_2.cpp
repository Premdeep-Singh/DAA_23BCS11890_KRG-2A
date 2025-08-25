// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

#include <bits/stdc++.h>

using namespace std;


// Solution 
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == INT_MIN) return 1/(myPow(x, INT_MAX) * x);
        if (n < 0) return 1/myPow(x, -n);

        double h = myPow(x, n/2);
    
        if (n % 2 == 0) return h * h;
        else return x * h * h;
    }
};

int main() {
    Solution sol;
    double x = 2.0;
    int n = -2;

    cout << sol.myPow(x, n) << endl;
    return 0;
}
