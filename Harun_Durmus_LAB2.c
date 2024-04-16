#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Mat(i,j) (*(Mat+(i)*(r)+(j)))
#define A(i,j) (*(A+(i)*size+(j)))
double determinant(double *Mat, int r){
	#define TempM(i,j) (*(TempM+(i)*(r-1)+(j)))
	double det=0;
	double temp;
	int i,j,k,c=0;
	if(r==1){
		det=Mat(0,0);
	}
	else{
		double *TempM;
		TempM=malloc(sizeof(double)*(r-1)*(r-1));
		for(k=0;k<r;k++){
			c=0;
			for(i=0;i<r;i++){
				for(j=0;j<r;j++){
					if(i!=0 && j!=k){
						TempM((c/(r-1)),(c%(r-1)))=Mat(i,j);
						c++;
					}
				}
			}
			temp=determinant(TempM,r-1);
			if(0==(k%2))
				det += temp*Mat(0,k);
			else
				det -= temp*Mat(0,k);
		}
		free(TempM);
	}
	return det;
}
void posdef(double *Mat,int r){
	int i,j,x=1,positive=0,negative=0,neither=0;
	double *ttemp,deter=0;
	while(x!=r+1){
		#define ttemp(i,j) (*(ttemp+(i)*(x)+(j)))
		ttemp=malloc(sizeof(double)*(x)*(x));
		// obtaining temporary 1x1,2x2,3x3,... upper left matrices from Mat
		for(int y=0;y<x;y++){
			for(int z=0;z<x;z++){
				ttemp(y,z)=	Mat(y,z);
			}
		}
		// determinant of each 1x1,2x2,3x3,... temp matrices then obtaining the data of positiveness,negativeness or neither
				deter=determinant(ttemp,x);
				printf("----------\n");
				for(int k=0;k<x;k++){
					for(int m=0;m<x;m++){
						printf("%lf ", ttemp(k,m));
					}
					printf("\n");
				}
				printf("----------\n");
				printf("determinant = %lf\n",deter);
				if(deter>0){
					positive++;
				}
				else if(deter<0){
					negative++;
				}
				else{
					neither++;
				}
		x++;
		free(ttemp);
		#undef ttemp
	}
	if(positive==r){
		printf("Matrix is positive definite\n");
	}
	else if(negative==r){
		printf("Matrix is negative definite\n");
	}
	else{
		printf("Matrix is neither positive nor negative definite\n");
	}
}
int main(){
	int i,j,size;
	double *A;
	printf("Enter the matrix size (for example, enter 3 for 3x3 matrix)\n");
	scanf("%d",&size);
	A=malloc(sizeof(double)*(size)*(size));
	printf("Enter the matrix coefficients one by one\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			scanf("%lf",&A(i,j));
		}
	}
	posdef(A,size);
	free(A);
	return 0;
}

#undef A
#undef Mat
#undef TempM










