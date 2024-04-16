#include <stdio.h>
#include <math.h>

double f(double x) {
    return 2*pow(x, 3) - 10*pow(x, 2) + 3*x + 5;
}

double iterative_method(double x0, double x1, int Nmax, double epsilon) {
    double xi_minus_1 = x0;
    double xi = x1;
    
    for (int i = 1; i <= Nmax; i++) {
        double fi_minus_1 = f(xi_minus_1);
        double fi = f(xi);
        
        double xi_plus_1 = xi - (fi * (xi - xi_minus_1)) / (fi - fi_minus_1);
        
        double error = fabs(xi_plus_1 - xi);
        
        if (error < epsilon) {
            return xi_plus_1;
        }
        
        xi_minus_1 = xi;
        xi = xi_plus_1;
    }
    
    printf("Maximum iterations reached!\n");
    return 0;
}

int main() {
    double x0, x1, epsilon;
    int Nmax;
    
    printf("Enter the initial estimates x0 and x1: ");
    scanf("%lf %lf", &x0, &x1);
    
    printf("Enter the maximum number of iterations Nmax: ");
    scanf("%d", &Nmax);
    
    printf("Enter the tolerable error epsilon: ");
    scanf("%lf", &epsilon);
    
    double solution = iterative_method(x0, x1, Nmax, epsilon);
    
    if (solution != 0) {
        printf("Solution found: %.4lf\n", solution);
    }
    
    return 0;
}
