#include <stdio.h>
#include <math.h>

#define MAXSIZE 10 // maximum size of the array

// function to calculate the value of the polynomial at a given x
float polysum(int order, float array[MAXSIZE], float x);

int main() {
    float coeffs[MAXSIZE], x1, x2, step_size, f1, f2, fx, root, root1; // variables for storing inputs and calculated values
    int order, max_iter, iter_count = 0, iter_count1; // variables for storing inputs and iteration count

    // get inputs from the user
    printf("Enter the order of the polynomial: ");
    scanf("%d", &order);

    printf("Enter %d coefficients: ", order+1);
    for(int i = 0; i <= order; i++) {
        scanf("%f", &coeffs[i]);
    }

    printf("Enter interval values (x1,x2), step size, and maximum iterations for bisection method: ");
    scanf("%f%f%f%f", &x1, &x2, &step_size, &max_iter);

    // calculate polynomial values at x1 and x2
    f1 = polysum(order, coeffs, x1);
    f2 = polysum(order, coeffs, x2);

    // find root using interval method
    fx = f1;
    while(fx * polysum(order, coeffs, x1 + step_size) >= 0) { // while the product of fx and the polynomial value at the next x is greater than or equal to 0
        x1 += step_size; // increment x1 by step_size
        fx = polysum(order, coeffs, x1); // calculate polynomial value at x1
        iter_count++; // increment iteration count
    }
    root = x1; // set root to the final x1 value
    root1 = root; // copy the value of root to root1 for later use
    iter_count1 = iter_count; // store the iteration count for later use

    // reset iter_count
    iter_count = 0;

    // find root using bisection method
    float prev_root = 0; // to store previous root value
    while(iter_count < max_iter) {
        root = (x1 + x2) / 2; // calculate the midpoint of x1 and x2
        fx = polysum(order, coeffs, root); // calculate polynomial value at the midpoint

        if(fabs(fx) < 0.000001) { // if the absolute value of the polynomial value at the midpoint is less than 0.000001
            break; // break out of the loop
        } else if(f1 * fx < 0) { // if the product of the polynomial value at x1 and the polynomial value at the midpoint is less than 0
            x2 = root; // set x2 to the midpoint
        } else { // if the product of the polynomial value at x1 and the polynomial value at the midpoint is greater than or equal to 0
            x1 = root; // set x1 to the midpoint
            f1 = fx; // update the value of f1 to fx
        }

        // check if the root is not changing significantly in consecutive iterations
        if(fabs(root - prev_root) < 0.000001) {
            break;
        }
        prev_root = root;
		printf("f(%f)=%f , f(%f)=%f , f(%f)=%f\n",x1,polysum(order,coeffs,x1),x2,polysum(order,coeffs,x2),root,polysum(order,coeffs,root));
        iter_count++;
    }
     printf("Interval method:\n");
    printf("Root = %f\n", root1);
    printf("Number of iterations: %d\n", iter_count1);
    printf("Bisection method:\n");
    printf("Root = %f\n", root);
    printf("Number of iterations: %d\n", iter_count);

    return 0;
}

// function to calculate the value of the polynomial at a given x
float polysum(int order, float array[MAXSIZE], float x) {
    float sum = 0;
    for(int i = 0; i <= order; i++) {
        sum += array[i] * pow(x, order-i);
    }
    return sum;
}
