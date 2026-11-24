#include <iostream>
#include <iomanip>
#include <limits.h>

using namespace std;

unsigned long long magnitude(long long x) {
    if (x < 0)
        return (unsigned long long)(-(x + 1)) + 1ULL;

    return (unsigned long long)x;
}

unsigned long long bitwiseOr(signed char a, short b, int c,
                             long d, long long e) {
    return magnitude(a) | magnitude(b) | magnitude(c)
           | magnitude(d) | magnitude(e);
}

int countBits(unsigned long long x) {
    int count = 0;

    while (x != 0) {
        x &= x - 1;
        count++;
    }

    return count;
}

int main() {
    signed char a;
    short b;
    int c, temp;
    long d;
    long long e;

    if (!(cin >> temp >> b >> c >> d >> e) ||
        temp < SCHAR_MIN || temp > SCHAR_MAX)
        return 1;

    a = (signed char)temp;

    long long q = (long long)a / 5 + b / 5
                  + c / 5 + d / 5 + e / 5;

    int r = (int)(a % 5 + b % 5 + c % 5 + d % 5 + e % 5);

    long double average = (long double)q + r / 5.0L;

    unsigned long long result = bitwiseOr(a, b, c, d, e);

    cout << fixed << setprecision(3);
    cout << "Average: " << average << '\n';
    cout << "OR: " << result << '\n';
    cout << "Set bits: " << countBits(result) << '\n';

    return 0;
}