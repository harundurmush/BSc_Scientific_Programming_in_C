#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define L 0.0
#define R 20.0
#define number_of_panels(I,J) (*(number_of_panels+(I)*10+(J)))
#define dnumber_of_panels(I,J) (*(dnumber_of_panels+(I)*10+(J)))
double f1(double x){
	double y1value;
	y1value=20+((0.5)*exp((0.2)*x));
	return y1value;
}
double f2(double x){
	double y2value;
	y2value=50+((0.01)*pow(x,3));
	return y2value;
}
double rectangular(double (*f)(double),double n){
	double l_integral=0;
	double stepsize,i=L;
	stepsize=(R-L)/n;
	while(i<R){
		l_integral += f(i)*stepsize;
		i += stepsize;
	}
	return l_integral;
}
double trapezoidal(double (*f)(double),double n){
	double r_integral=0,l_integral=0,t_integral=0;
	double stepsize,i=L;
	stepsize=(R-L)/n;
	while(i<R){
		l_integral += f(i)*stepsize;
		r_integral += f(i+stepsize)*stepsize;
		t_integral += (r_integral+l_integral)/2;
		i += stepsize;
	}
	return t_integral;
}
int *number_of_panels_generator(){
	double x=1;
	int *number_of_panels;
	int i=0;
	number_of_panels=malloc(sizeof(double)*(10)*(10));
	while(i<10){
		number_of_panels(i,0)=100*x;
		x++;
		i++;
	}
	return number_of_panels;
}
double absolute(double va,double ve){
	double error1;
	error1=fabs(ve-va);
	return error1;
}
double relative(double va,double ve){
	double error2;
	error2=fabs((ve-va)/ve);
	return error2;
}
double percentage(double va,double ve){
	double error3;
	error3=fabs((ve-va)/ve)*100;
	return error3;
}
int main(){
	int *dnumber_of_panels;
	int i=0;
	dnumber_of_panels=malloc(sizeof(double)*(10)*(10));
	double rect1,rect2,trap1,trap2,rectarea,traparea,abs_error,rela_error,per_error;
	printf("\t       Rect f1 Rect. f2 Rect.area | Abs.Error Rela.Error Per.Error(%c)\n",'%');
	while(i<10){
		dnumber_of_panels(i,0)=*number_of_panels_generator();
		printf("Panel no:%d | ",dnumber_of_panels(i,0));
		rect1=rectangular(f1,dnumber_of_panels(i,0));
		rect2=rectangular(f2,dnumber_of_panels(i,0));
		rectarea=fabs(rect2-rect1);
		abs_error=absolute(rectarea,866.04929);
		rela_error=relative(rectarea,866.04929);
		per_error=percentage(rectarea,866.04929);	
		printf("%.2lf  ",rect1);
		printf("%.2lf\t",rect2);
		printf("%.2lf\t  | ",rectarea);
		printf("%.2lf     ",abs_error);
		printf("%.2lf       ",rela_error);
		printf("%.2lf",per_error);
		printf("\n");
		i++;
	}
	printf("\n");
	printf("\n");
	printf("\t       Trap. f1 Trap. f2 Trap.area| Abs.Error Rela.Error Per.Error(%c)\n",'%');
	i=0;
	while(i<10){
		dnumber_of_panels(i,0)=*number_of_panels_generator();
		printf("Panel no:%d | ",dnumber_of_panels(i,0));
		trap1=trapezoidal(f1,dnumber_of_panels(i,0));
		trap2=trapezoidal(f2,dnumber_of_panels(i,0));
		traparea=fabs(trap2-trap1);
		abs_error=absolute(traparea,866.04929);
		rela_error=relative(traparea,866.04929);
		per_error=percentage(traparea,866.04929);	
		printf("%.2lf ",trap1);
		printf("%.2lf ",trap2);
		printf("%.2lf | ",traparea);
		printf("%.2lf  ",abs_error);
		printf("%.2lf      ",rela_error);
		printf("%.2lf",per_error);
		printf("\n");
		i++;
	}
	free(dnumber_of_panels);
}













