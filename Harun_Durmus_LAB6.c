#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double p_t(double t){
	return (double)(0.001*60.0*(exp((-50.0)*t)));
}
double l_rectangular(double (*f)(double),double a,double b,int n){
	double l_integral=0;
	double stepsize;
	stepsize=(b-a)/n;
	double i=a;
	/*I used while loops instead of for loops because for loops error with double incrementing values.*/
	while(i<b){
		l_integral += f(i)*stepsize;
		i += stepsize;
	}
	if(i!=b){
		l_integral += f(b)*(b-i);
	}
	// This if part and the one in r_rectangular below, checks the last panel.
	return (double)l_integral;
}
double r_rectangular(double (*f)(double),double a,double b,int n){
	double r_integral=0;
	double stepsize,i=a;
	stepsize=(b-a)/n;
	while(i<b){
		r_integral += f(i+stepsize)*stepsize;
		i += stepsize;
	}
	if(i!=b){
		r_integral += f(i)*(b-i);
	}
	return (double)r_integral;
}
double simpson(double (*f)(double),double a,double b,int n){
	double answer,h,x;
	int i;
	answer = f(a);
	h = (b-a)/n;
	for(i=1;i<=n;i++){
		x=a+(i*(1.0)*h);
		answer = answer + 4.0*f(x-h/2.0) + 2.0*f(x);
	}
	answer = answer - f(b);
	return (h*answer/6.0);
}
double main(){
	/*My output screen might be different than in the sheet because my command window size can not go wider
	so I changed the titles a little bit.*/
	double a,b,trapezoidal;
	int i;
	printf("Enter a : ");
	scanf("%lf",&a);
	printf("Enter b : ");
	scanf("%lf",&b);
	printf("Performance comparison of Left Rectangular, Trapezoidal, Simpson's methods on\npower\n\n");
	printf("\t\t\tLeft Rectangular   Trapezoidal     Simpson's\n");
	printf("\t\t\t----------------   -----------     ---------\n");
	for(i=10;i<=100;i+=10){
		printf("Number of panels: %d\t%.10lf\t   %.10lf\t   %.10lf\n",
		i,
		l_rectangular(p_t,a,b,i),
		((l_rectangular(p_t,a,b,i)+r_rectangular(p_t,a,b,i))/2),
		simpson(p_t,a,b,i));                                                          
	}
}













