#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define d 0.000001



double polysum(int num, double array[MAXSIZE],double x){
	
	double result=0;
	double a=1;
	
	for(int i=num;i>=0;i--){
		for(int j=i;j>0;j--){
			a*=x;
		}
		a*=array[num-i];
		result+=a;
		a=1;
		
	}
	return (result);
	
}



int main(){
	
	int degree;
	double coeff[MAXSIZE];
	double x_L, x_U, step;
	printf("Enter the degree of the polynomial:\n");
	scanf("%d",&degree);
	printf("Enter the coefficients of the polynomial:\n");
	for(int i =0;i<=degree;i++){
		scanf("%lf",&coeff[i]);
	}
	
	printf("given polynomial is:\n");
	for(int i=0;i<=degree;i++){
		if(coeff[i]>0){
			printf("+");
		}
		printf("%lf x^%d ",coeff[i],degree-i);

	}
	
	printf("\nInput interval values (x_{L},x_{U}) and step size:\n");
	scanf("%lf",&x_L);
	scanf("%lf",&x_U);
	scanf("%lf",&step);
	double a,b,c;
	
	
	for(double i=x_L;i<=x_U;i+=step){
		a=polysum(degree,coeff,i);
		b=polysum(degree,coeff,i+step-d);
		
		
		if((a*b)<=0){
			printf("root found=%lf\n",(i+i+step)/2);
		}

		
		
	}
	
	
	
		
	return 0;
}
