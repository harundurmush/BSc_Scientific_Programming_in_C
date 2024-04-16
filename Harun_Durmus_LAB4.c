#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 10
double polysum(int order,float array[MAXSIZE],double x){
	double yvalue=0;
	int j=0;
	for(int i=order;i>=0;i--){
		yvalue += array[j]*(pow(x,i));
		j++;
	}
	return yvalue;
}
double derivative_polysum(int order, float array[MAXSIZE],double x){
	double ydvalue=0;
	int j=0;
	for(int i=order;i>=1;i--){
		ydvalue += array[j]*i*(pow(x,i-1));
		j++;
	}
	return ydvalue;
}
double Newton_method(int order,float array[MAXSIZE],double x0,double epsilon, int N){
	double root,f0,g0,xsum,f,g,x;
	f0 = polysum(order,array,x0);
	g0 = derivative_polysum(order,array,x0);
	// I generalized the parameters after I reached x0,f0,g0 to x,f,g
	f = f0;
	g = g0;
	x = x0;
	printf("Iteration \tx0 \t\tf(x0) \t\tx1 \t\tf(x1)\n");
	for(int i=1;i<N;i++){
		printf("%d\t\t",i);
		printf("%lf\t",x);
		xsum = x - (f/g);
		printf("%lf\t",f);
		printf("%lf\t",xsum);
		f = polysum(order,array,xsum);
		printf("%lf",f);
		g = derivative_polysum(order,array,xsum);
		x = xsum;
		// I used several printf functions in order to not get confused,
		// also x and f values have to print twice, second ones are iterated ones.
		printf("\n");
		if(fabs(polysum(order,array,xsum)) <= epsilon){
			printf("Root = %lf\n",xsum);
			return xsum;
		}
	}
	if(fabs(polysum(order,array,xsum)) > epsilon){
		printf("Not Convergent.\n");
	}
	return xsum;
}
int main(){
	float coeff[MAXSIZE];
	double epsilon,x0;
	int degree,N;
	printf("Enter the degree/order of the polynomial\n");
	scanf("%d",&degree);
	int k=degree; // is for displaying power of the x in polynomial
	printf("Enter the coefficients of the polynomial\n");
	for(int i=0;i<=degree;i++){
		scanf("%f",&coeff[i]);
	}
	printf("Given polynomial is:\n");
	for(int i=0;i<=degree;i++){
		if(coeff[i]>=0){
			printf("+");
		}
		else if(coeff[i]<0){
			printf("-");
		}
		printf("%.2f*x^%d",fabs(coeff[i]),k);
		k--;
	}
	printf("\n\n");
	printf("Enter the tolerable error, epsilon:\n");
	scanf("%lf",&epsilon);
	printf("\nEnter the maximum number of iterations, N:\n");
	scanf("%d",&N);
	printf("\nEnter the initial point, x0:\n");
	scanf("%lf",&x0);
	printf("\n");
	Newton_method(degree,coeff,x0,epsilon,N);
	return 0;
}







