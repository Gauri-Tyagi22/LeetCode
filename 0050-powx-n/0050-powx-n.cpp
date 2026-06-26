class Solution {
public:
    double power(double x, long long n) {
        if (n == 0)
            return 1;

        if (n % 2 == 0)
            return power(x * x, n / 2);

        return x * power(x, n - 1);
    }

    double myPow(double x, int n) {
        long long powerVal = n;

        if (powerVal < 0) {
            x = 1 / x;
            powerVal = -powerVal;
        }

        return power(x, powerVal);
    }
};