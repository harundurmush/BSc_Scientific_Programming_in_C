#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 100
double polysum(int num,double array[MAXSIZE],double x){
	int i,j,k=num;
	double y_value;
	for(i=0;i<num+1;i++){
		y_value = 0;
		y_value += (array[i] * pow(x,k));
	}	
	return y_value;	
}

int main(){
	int num,stepsize,j;
	double x_L,x_U,tempxL,tempxU;
	printf("Enter the order/degree of the polynomial\n");
	scanf("%d", &num);
	int x = num;
	double coeff[num+1];
	char sign[num+1];
	double roots[num],temproot[MAXSIZE];
	printf("Enter the coefficients of the polynomial\n");
	for(int i=0;i<num+1;i++){
		scanf("%lf",&coeff[i]);
		if(coeff[i]>0){
			sign[i] = '+';
		}
		else if(coeff[i]<0){
			sign[i] = '-';
		}
		else{
			sign[i]=' ';
		}
	}
	printf("Given polynomial is:\n");
	for(int i=0;i<num+1;i++){
		printf("%c %lfx^%d ",sign[i],fabs(coeff[i]),x);
		x--;
	}
	printf("\n");
	printf("Input interval values (x_{L},x_{U}) and step size:\n");
	scanf("%lf %lf %d",&x_L,&x_U,&stepsize);
	for(int i=0;i<num;i++){
		tempxL=x_L;
		tempxU=x_U;
		for(int j=0;j<fabs(x_U-x_L)/stepsize;j++){
			if(polysum(num,coeff,tempxL)*polysum(num,coeff,tempxU)<=0){
				tempxU-=stepsize;
			}
			else if(polysum(num,coeff,tempxL)*polysum(num,coeff,tempxU)>0){
				temproot[j]= tempxU+stepsize;
				tempxU=x_U;
			}
			else{
				temproot[j]=(tempxL+tempxU)/2;
			}
		}
		roots[i]=temproot[j];
	}
	for(int i=0;i<num;i++){
		printf("Root Found=%lf\n",roots[i]);
	}
}
