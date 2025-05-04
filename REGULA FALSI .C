#include <iostream>
#include <cmath>
using namespace std;

// Define the function
double f(double x) {
    return x * x - 4;  // Example: root at x = ±2
}

int main() {
    double a = 0, b = 5, c;
    double tol = 0.001;
    int max_iter = 100, iter = 0;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. f(a) and f(b) must have opposite signs.\n";
        return 1;
    }

    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
        iter++;
    } while (fabs(f(c)) > tol && iter < max_iter);

    cout << "Root = " << c << " after " << iter << " iterations\n";
    return 0;
}
