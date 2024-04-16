#include <stdio.h>
#include <math.h>
#define L 1
#define R 10
double f1(double x){
	double y1value = exp((-0.1)*pow(x,2));
	return y1value;
}
double f2(double x){
	double y2value = 2*(exp((-0.2)*x));
	return y2value;
}
double rectangular(double (*f)(double), double n){
	double integral=0;
	double stepsize = (9)/(n);
	for(double j=1; j<10; j+stepsize){
		integral += f(j)*(stepsize);
	}
	return integral;
}
double trapezoidal(double (*f)(double), double n){
	double t_integral=0,l_integral=0,r_integral=0;
	double stepsize = (R-L)/(n);
	for(int j=L; j<R; j+stepsize){
		l_integral += f(j)*stepsize;
		r_integral += f(j+stepsize)*stepsize;
		t_integral += (l_integral + r_integral)/2;
	}
	return t_integral;
}
int main(){
	double rectf1,trapf1,rectf2,trapf2;
	printf("\t\t Rect. f1 \t Trap. f1 \t Rect. f2 \t Trap. f2\n");
	for(double i=50;i<=1000;i+50){
		//double (*f)(double)=&f1;
		rectf1=rectangular(f1,i);
		printf("%lf\n",rectf1);
		
	}
	return 0;
}








