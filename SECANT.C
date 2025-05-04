#include <iostream>
#include <cmath>
using namespace std;

// Define the function
double f(double x) {
    return x * x - 4;  // Example: root at x = ±2
}

int main() {
    double x0 = 2, x1 = 3, x2;
    double tol = 0.001;
    int max_iter = 100, iter = 0;

    do {
        if (f(x1) - f(x0) == 0) {
            cout << "Division by zero error!\n";
            return 1;
        }

        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
        iter++;

    } while (fabs(f(x2)) > tol && iter < max_iter);

    cout << "Root = " << x2 << " after " << iter << " iterations\n";
    return 0;
}
