#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#define MAXSIZE 45
#define PI 3.14159
double main(){
	int i,j,k,m,t,ffcount=0,fdcount=0,ddcount=0,dccount=0,cccount=0,cbcount=0,bbcount=0,bacount=0,aacount=0;
	double a,b,c,d,e,f,g,h,n,x1;
	double ss,a_ort,sum1=0,sum2=0;
	double y[MAXSIZE];
	double x[MAXSIZE]={52,44,48,72,64,
					   40,52,28,52,60,
					   12,84,52,48,68,
					   16,80,84,80,48,
					   92,48,28,72,48,
					   44,84,28,80,36,
					   48,44,12,56,84,
					   12,64,44,32,72,
					   24,28,80,92,40};
	for(i=0;i<MAXSIZE;i++){
		sum1 += x[i];
	}
	a_ort=sum1/MAXSIZE;
	for(j=0;j<MAXSIZE;j++){
		sum2 += pow((x[j]-a_ort),2);
	}
	ss = sqrt(sum2/(MAXSIZE-1));
	for(k=0;k<MAXSIZE;k++){
		//y[k]=(exp((pow(x[k]-a_ort,2))/(-2*pow(ss,2)))/(ss*sqrt(2*PI)));
		y[k]=(10*((x[k]-a_ort)/ss))+50;
		/*if(y[k]<0){
			y[k]=0;
		}
		else if(y[k]>100){
			y[k]=100;*/
		}
		a=a_ort-4*(ss/10);
		b=a_ort-3*(ss/10);
		c=a_ort-2*(ss/10);
		d=a_ort-(ss/10);
		e=a_ort;
		f=a_ort+(ss/10);
		g=a_ort+2*(ss/10);
		h=a_ort+3*(ss/10);
		n=a_ort+4*(ss/10);
	for(m=0;m<MAXSIZE;m++){
		printf("Student %d : %.3lf ",m+1,y[m]);
		if(y[m]<b){
			printf("FF\n");
			ffcount++;
		}
		else if(y[m]>b && y[m]<c){
			printf("FD\n");
			fdcount++;
		}
		else if(y[m]>c && y[m]<d){
			printf("DD\n");
			ddcount++;
		}
		else if(y[m]>d && y[m]<e){
			printf("DC\n");
			dccount++;
		}
		else if(y[m]>e && y[m]<f){
			printf("CC\n");
			cccount++;
		}
		else if(y[m]>f && y[m]<g){
			printf("CB\n");
			cbcount++;
		}
		else if(y[m]>g && y[m]<h){
			printf("BB\n");
			bbcount++;
		}
		else if(y[m]>h && y[m]<n){
			printf("BA\n");
			bacount++;
		}
		else if(y[m]>n){
			printf("AA\n");
			aacount++;
		}
	}
	printf("AA : %d\nBA : %d\nBB : %d\nCB : %d\nCC : %d\nDC : %d\nDD : %d\nFD : %d\nFF : %d\n",aacount,bacount,bbcount,cbcount,cccount,dccount,ddcount,fdcount,ffcount);
	i=0;
	while(y[i]){
		x1=y[i]*79/100;
		for(j=0;j<79;j++){
			for(k=0;k<MAXSIZE;k++){
				if(floor(x1)==j){
				printf("+");
			}
			else{
				printf("O");
			}
			}
		}
		i++;
		printf("\n");
	}
	return 0;
}
