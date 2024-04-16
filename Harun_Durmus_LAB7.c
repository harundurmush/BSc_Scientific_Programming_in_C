#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define W(I,J) (*(W+(I)*4+(J)))
#define MAXSIZE 1000
double fY(double x){
	return (double)(exp(-(pow(x,5.0)/5.0)+(pow(x,3.0)/3.0)-(pow(x,2.0)/2.0)));
}
double fYdx(double x,double y){
	return (double)y*(-pow(x,4.0)+pow(x,2.0)-x);
}
double euler(double xFirst,double yFirst,double xLast,double stepSize,double A[]){
	int k=0;
	A[k]=yFirst;
	for(;xFirst<=xLast;xFirst+=stepSize){
		yFirst += stepSize*fYdx(xFirst,yFirst);
		k+=1;
		A[k]=yFirst;
	}
}
double midpoint(double xFirst,double yFirst,double xLast,double stepSize,double B[]){
	int k=0;
	B[k]=yFirst;
	for(;xFirst<=xLast;xFirst+=stepSize){
		yFirst += stepSize*fYdx(xFirst+(stepSize/2.0),yFirst+(stepSize*fYdx(xFirst,yFirst)/2.0));
		k+=1;
		B[k]=yFirst;
	}
}
double RK4(double xFirst,double yFirst,double xLast,double stepSize,double C[]){
	int k=0;
	double k1,k2,k3,k4;
	C[k]=yFirst;
	for(;xFirst<=xLast;xFirst+=stepSize){
		k1=fYdx(xFirst,yFirst);
		k2=fYdx(xFirst+(stepSize/2.0),yFirst+(stepSize*k1/2.0));
		k3=fYdx(xFirst+(stepSize/2.0),yFirst+(stepSize*k2/2.0));
		k4=fYdx(xFirst+stepSize,yFirst+(stepSize*k3));
		yFirst+=stepSize*(k1+2.0*k2+2.0*k3+k4)/6.0;
		k+=1;
		C[k]=yFirst;
	}
}
double exact(double xFirst,double yFirst,double xLast,double stepSize,double D[]){
	int i,k=0;
	D[k]=fY(xFirst);
	for(;xFirst<=xLast;xFirst+=stepSize){
		k+=1;
		D[k]=fY(xFirst+stepSize);
	}
}
double main(){
	int i,j;
	double x0,y0,xLast,stepSize,allocation,*W;
	double x,x1,x2,x3,x4,y1,y2,y3,y4;
	printf("y(%.1lf) = %.4lf  and  g(%.1lf,%.1lf) = %.4lf\n\n\n",-0.1,fY(-0.1),-0.1,0.5,fYdx(-0.1,0.5));
	printf("Please enter x0 and y0\n");
	scanf("%lf %lf",&x0,&y0);
	printf("Please enter xLast and stepSize\n");
	scanf("%lf %lf",&xLast,&stepSize);
	allocation=(xLast-x0)/stepSize;
	double A[MAXSIZE],B[MAXSIZE],C[MAXSIZE],D[MAXSIZE];
	W=malloc(sizeof(double)*5*allocation);
	x=x0;
	x1=x0;
	x2=x0;
	x3=x0;
	x4=x0;
	y1=y0;
	y2=y0;
	y3=y0;
	y4=y0;
	euler(x1,y1,xLast,stepSize,A);
	midpoint(x2,y2,xLast,stepSize,B);
	RK4(x3,y3,xLast,stepSize,C);
	exact(x4,y4,xLast,stepSize,D);
	for(i=0;i<4;i++){
		for(j=0;j<=allocation;j++){
			if(i==0)
				W(j,i)=A[j];
			if(i==1)
				W(j,i)=B[j];
			if(i==2)
				W(j,i)=C[j];
			if(i==3)
				W(j,i)=D[j];
		}
	}
	printf("                        Euler       Midpoint    RK4         Exact\n");
	printf("                        -----       --------    ---         -----\n");
	for(i=0;i<=allocation;i++,x+=stepSize){
		printf("Step ");
		if(i<10 || x>=0)
			printf(" ");
		printf("%d-y(%lf)",i,x);
		for(j=0;j<4;j++){
			
			printf("--- ");
			printf("%lf",W(i,j));
		}
		printf("\n");
	}
	free(W);
}

#undef W
