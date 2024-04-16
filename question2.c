#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define A(I,J) (*(A+I*(n)+(J)))
#define B(I,J) (*(B+I*(n)+(J)))
#define C(I,J) (*(C+I*(n)+(J)))
void mat_mlt(int m,int n,int p,double *A,double *B,double *C){
	int i,j,k;
	for(i=0;i<m;i++){
		for(j=0;j<p;j++){
			for(k=0;k<n;k++){
				C(i,j)=A(i,k)*B(k,j);
			}
		}
	}	
}
void mat_trnps(int m,int n,double *A,double *B){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			B(i,j)=A(j,i);
		}
	}
}
void mat_display(int m,int n,double *A){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%.0lf ",A(i,j));
		}
		printf("\n");
	}
}
int main(){
	int i,j,operation;
	double *A,*B,*C;
	int m,p,r,n,s2,s1;
	printf("Select an operation:\n1.Matrix Multiplication\n2.Matrix Tranpose\n");
	scanf("%d",&operation);
	switch(operation){
		case 1:
			printf("\n\nEnter the number of rows of first operand matrix\n");
			scanf("%d",&m);
			printf("Enter the number of columns of first operand matrix\n");
			scanf("%d",&n);
			A = (double*)malloc(sizeof(double)*m*n);
			printf("Enter elements of A:\n");
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					scanf("%lf",&A(i,j));
				}
			}
			printf("Enter the number of rows of second operand matrix\n");
			scanf("%d",&r);
			printf("Enter the number of columns of second operand matrix\n");
			scanf("%d",&p);
			B = (double*)malloc(sizeof(double)*r*p);
			printf("Enter elements of B:\n");
			for(i=0;i<r;i++){
				for(j=0;j<p;j++){
					scanf("%lf",&B(i,j));
				}
			}
			if(n==r){
				C = (double*)malloc(sizeof(double)*m*p);
				mat_mlt(m,n,p,A,B,C);
				printf("Result:\n");
				mat_display(m,p,C);
			}
			else{
				printf("Multiplication can not be applied\n");
			}
		case 2:
			printf("\n\nEnter the number of rows of matrix\n");
			scanf("%d",&m);
			printf("Enter the number of columns of matrix\n");
			scanf("%d",&n);
			A = (double*)malloc(sizeof(double)*m*n);
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					scanf("%lf",&A(i,j));
				}
			}
			B = (double*)malloc(sizeof(double)*m*n);
			mat_trnps(m,n,A,B);	
			printf("Result:\n");
			mat_display(m,n,B);	
	}
	free(A);
	free(B);
	free(C);
	return 0;	
}
