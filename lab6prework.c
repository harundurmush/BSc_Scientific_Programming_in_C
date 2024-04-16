#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define start 0.0
#define end 10.0
#define PI 3.142857
float phi_t(float t){
	return (float)(sin((PI)*t*4.0));
}
float phi_diff(float t,float h){
	return (float)((phi_t(t+h)-phi_t(t))/h);
}
float xt(float t,float h){
	float VDC=1.0;
	return (float)((0.5)*cos(((PI)*t*20.0)+(phi_diff(t,h)))+(VDC));
}
float simpson(float (*f)(float,float),float n){
	float answer,k,x;
	int i;
	answer = f(start,end);
	k = (end-start)/n;
	for(i=1;i<=n;i++){
		x=start+(i*1.0)*k;
		answer = answer + 4.0*f(x-k/2,k) + 2.0*f(x,k);
	}
	answer = answer - f(end,k);
	return (float)(k*answer/6.0);
}
float adaptive_simpson(float (*f)(float,float),float n0, float tol){
	float check=tol+1.0;
	float lowval,val;
	lowval = simpson(f,n0);
	while(check>tol){
		n0=2.0*n0;
		val=simpson(f,n0);
		check=fabs((val-lowval)/val);
		lowval=val;		
	}
	return (float)(val);
}
void main(){
	float tolerance=0.0001;
	int n1;
	printf("Number of Panels\tSimpson's\tAdaptive Simpson's\n");
	printf("----------------------------------------------------------\n");
	for(n1=10;n1<=200;n1+=10){
		n1 *= 1.0;
		printf("\t%d\t\t%f\t%f\n",n1,simpson(xt,n1),adaptive_simpson(xt,n1,tolerance));
	}
}



























