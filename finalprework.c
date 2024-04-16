#include <stdio.h>
#include <math.h>
#define max(x,y) (((x)>=(y))?x:y)
//fabs(j-y1-m1*(i-x1))<=0.79 && fabs(j-y2-m2*(i-x2))<=0.79 && fabs(j-y1-m3*(i-x1))<=0.79
//check_points is for sorting points
void check_points(float x1,float y1,float x2,float y2,float x3,float y3,float x[3],float y[3]){
	float t;
	int i,j;
	x[0]=x1;
	x[1]=x2;
	x[2]=x3;
	y[0]=y1;
	y[1]=y2;
	y[2]=y3;
	for (i=0; i<2; i++){
    	for (j=i+1; j<3; j++){
        	if (x[i] > x[j]){
         		t=x[i];
         		x[i] = x[j];
         		x[j] = t;
      		}
   		}
	}
	for (i=0; i<2; i++){
    	for (j=i+1; j<3; j++){
        	if (y[i] > y[j]){
         		t=y[i];
         		y[i] = y[j];
         		y[j] = t;
      		}
   		}
	}
	x1=x[0];
	x2=x[1];
	x3=x[2];
	y1=y[2];
	y2=y[0];
	y3=y[1];
	
	return x,y;
}
int main(){
	int i,j;
	float x1,y1,x2,y2,x3,y3,x[3],y[3];
	float m1,m2,m3;
	printf("Enter the points:\n");
	printf("x1 = ");
	scanf("%f",&x1);
	printf("y1 = ");
	scanf("%f",&y1);
	printf("x2 = ");
	scanf("%f",&x2);
	printf("y2 = ");
	scanf("%f",&y2);
	printf("x3 = ");
	scanf("%f",&x3);
	printf("y3 = ");
	scanf("%f",&y3);
	check_points(x1,y1,x2,y2,x3,y3,x,y);
	x[0]=x1;
	x[1]=x2;
	x[2]=x3;
	y[0]=y1;
	y[1]=y2;
	y[2]=y3;
	/*
	x1=10;
	y1=-10;
	x2=10;
	y2=-50;
	x3=50;
	y3=-30;*/
	m1 = ((y2-y1)/(x2-x1));
	m2 = ((y3-y2)/(x3-x2));
	m3 = ((y3-y1)/(x3-x1));
	printf("\nx1=%f y1=%f\nx2=%f y2=%f\nx3=%f y3=%f\n",x1,y1,x2,y2,x3,y3);
	for(j=0;j>-79;j--){
		for(i=0;i<79;i++){
			if((fabs(j-y1-m1*(i-x1))<=0.79 || fabs(j-y2-m2*(i-x2))<=0.79 || fabs(j-y1-m3*(i-x1))<=0.79) && i>=x1 && i<=x3 && j<=y1 && j>=y2){
				printf("+");
			}
			else{
				printf("o");
			}
		}
		printf("\n");
	}
}
