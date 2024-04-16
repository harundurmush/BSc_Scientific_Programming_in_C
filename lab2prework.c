#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define a(I,J) (*(A+(I)*(size)+(J)))
#define dA(I,J) (*(dA+(I)*(size)+(J)))
#define dC(I,J) (*(dC+(I)*(size)+(J)))
#define dD(I,J) (*(dD+(I)*(size)+(J)))
#define WORK(I,J) (*(WORK+(I)*(size+1)+(J)))
#define d(I,J) (*(d+(I)*(size)+(J)))
#define TRUE 1
#define FALSE 0

void mat_display(int size,double *A){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(a(i,j)<0)
				printf("%.3lf ",a(i,j));
			else
				printf(" %.3lf ",a(i,j));
		}
		printf("\n");
	}
	printf("\n");
}
void CreateIdentityMat(double *A, int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(i==j){
				a(i,j) = 1;
			}
			else{
				a(i,j) = 0;
			}
		}
	}
}
int main(){
	double *dA,*dC,*WORK,*dD;
	int size;
	printf("Enter size:\n");
	scanf("%d",&size);
	double m, max, temp,*d;
	int i,j,k,x=0,swap;
	d=(double*)malloc(size*size*sizeof(double));
	dA=(double*)malloc(size*size*sizeof(double));
	dC=(double*)malloc(size*size*sizeof(double));
	WORK=(double*)malloc(size*(size+1)*sizeof(double));
	dD=(double*)malloc(size*size*sizeof(double));
	CreateIdentityMat(dA,size);
	/*printf("Enter the A matrix\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			scanf("%lf",&dC(i,j));
		}
	}*/
	// Random Matrix Generator
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			dC(i,j)=(rand()%10);
		}
	}
	// Gauss-Jordan Elimination
	while(x!=size){
		for(i=0; i<size;i++){
				for(j=0; j<size; j++){
					WORK(i,j) = dC(i,j);
					WORK(i,size) = dA(i,x);
				}
			}
		for(i=0; i<size;i++){
			max = -1.0;
			for(k=i; k<size; k++)
				if(fabs(WORK(k,i)) > max){
					max = fabs(WORK(k,i));
					swap = k;
				}
			if(swap != i)
				for(k=i; k<=size; k++){
					temp = WORK(i,k);
					WORK(i,k) = WORK(swap,k);
					WORK(swap,k) = temp;
				}
			for(j=0; j<size; j++)
					if( j != i){
						m = WORK(j,i)/ WORK(i,i);
						for(k=i; k<=size; k++)
							WORK(j,k) -= m*WORK(i,k);
					}
				
		}
		for(i=0; i<size;i++){
				d(i,x)=WORK(i,size)/WORK(i,i);
				dD(i,x)=d(i,x);
		}
		x++;
	}
	printf("\n");
	printf("Identification Matrix\n");
	printf("---------------------\n");
	mat_display(size,dA);
	printf("Input Matrix\n");
	printf("------------\n");
	mat_display(size,dC);
	printf("Inverse of Input Matrix\n");
	printf("-----------------------\n");
	mat_display(size,dD);
	free(dA);
	free(dC);
	free(dD);
	free(WORK);
	free(d);
	
}

#undef dA
#undef dC
#undef dD
#undef WORK
#undef a
#undef d

