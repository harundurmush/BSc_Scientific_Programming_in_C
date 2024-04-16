#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double g_function(double Vc0,double R,double C,double Vs){
	return (1.0/(R*C))*(Vs-Vc0);
}
double y_exact(double t,double R,double C,double Vs){
	return Vs*(1.0-(exp(-t/(R*C))));
}
double euler(double t0,double Vc0,double (*g)(double,double,double,double),double h,double tlast,double R,double C,double Vs){
	double t=t0,V=Vc0;
	while(t<tlast){
		V+=h*g(V,R,C,Vs);
		t+=h;
	}
	return V;
}
double Error(double yex,double yeu){
	return fabs((yex-yeu)/yex)*100.0;
}
double main(){
	double t0,t_last,Vc0,R,C,Vs,h1,h2,h3,vex;
	double veu_h1,veu_h2,veu_h3;
	printf("input respectively\n");
	printf(" t0  Vc0\n");
	scanf("%lf",&t0);
	scanf("%lf",&Vc0);
	printf("input respectively\n");
	printf(" R  C  V\n");
	scanf("%lf",&R);
	scanf("%lf",&C);
	scanf("%lf",&Vs);
	printf("input step size\n");
	printf(" h1 : ");
	scanf("%lf",&h1);
	printf("input step size\n");
	printf(" h2 : ");
	scanf("%lf",&h2);
	printf("input step size\n");
	printf(" h3 : ");
	scanf("%lf",&h3);
	printf("input t_last\n t_last :");
	scanf("%lf",&t_last);
	vex=y_exact(t_last,R,C,Vs);
	printf("Exact Voltage : %lf\n",vex);
	veu_h1=euler(t0,Vc0,g_function,h1,t_last,R,C,Vs);
	veu_h2=euler(t0,Vc0,g_function,h2,t_last,R,C,Vs);
	veu_h3=euler(t0,Vc0,g_function,h3,t_last,R,C,Vs);
	printf("Percentage Error for h1=0.1: %lf\n",Error(vex,veu_h1));
	printf("Percentage Error for h2=0.01: %lf\n",Error(vex,veu_h2));
	printf("Percentage Error for h3=0.001: %lf\n",Error(vex,veu_h3));
	
	
}
