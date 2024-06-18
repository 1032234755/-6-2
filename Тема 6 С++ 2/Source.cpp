#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double f2(vector<double> x) {
    return 7 * pow(x[0], 2) + 2 * x[0] * x[1] + 5 * pow(x[1], 2) + x[0] - 10 * x[1];
}

vector<double> gradient_f2(vector<double> x) {
    double df_dx1 = 14 * x[0] + 2 * x[1] + 1;
    double df_dx2 = 2 * x[0] + 10 * x[1] - 10;
    return { df_dx1, df_dx2 };
}

vector<double> steepest_descent(double (*f)(vector<double>), vector<double>(*grad_f)(vector<double>), vector<double> x0, double lr = 0.01, int max_iter = 100) {
    vector<double> x = x0;
    for (int iter = 0; iter < max_iter; ++iter) {
        vector<double> grad = grad_f(x);
        for (size_t i = 0; i < x.size(); ++i) {
            x[i] -= lr * grad[i];
        }
    }
    return x;
}

int main() {
    vector<double> x0 = { 0.5, 0.5 };
    vector<double> solution = steepest_descent(f2, gradient_f2, x0);
    cout << "Решение методом наискорейшего спуска: [" << solution[0] << ", " << solution[1] << "]" << endl;
    return 0;
}
