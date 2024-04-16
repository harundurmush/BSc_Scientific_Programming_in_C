#include <stdio.h>
#include <stdlib.h>
#define a(I,J) (*(A+(I)*n+(J)))
#define b(I,J) (*(B+(I)*n+(J)))
#define c(I,J) (*(C+(I)*n+(J)))
#define dA(I,J) (*(dA+(I)*c1+(J)))
#define dB(I,J) (*(dB+(I)*c2+(J)))
#define dC(I,J) (*(dC+(I)*c1+(J)))

void mat_add(int m,int n,double *A,double *B,double *C){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			c(i,j)=a(i,j)+b(i,j);
		}
	}
}
void mat_mlt(int m,int n,int p,double *A,double *B,double *C){
	int i,j,k,multiplication;
	for(i=0;i<m;i++){
		for(j=0;j<p;j++){
			multiplication = 0;
			for(k=0;k<n;k++){
				multiplication += a(i,k)*b(k,j);
			}
			c(i,j) = multiplication;
		}
	}		
}
void mat_trnsps(int m,int n,double *A,double *B){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			b(i,j)=a(j,i);
		}
	}
}
int is_mat_equal(int m,int n,double *A,double *B){
	int i,j,k=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a(i,j)!=b(i,j)){
				k++;
			}
		}
	}
	return k;
}
void mat_display(int m,int n,double *A){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%lf ",a(i,j));
		}
		printf("\n");
	}
}
int main(){
	double *dA,*dB,*dC;
	int operation=0,r1,c1,r2,c2,i,j;
	while(operation != 9){
		printf("Choose operation to proceed:\n1. Matrix addition\n2. Matrix multiplication\n3. Matrix transpose\n4. Symmetric matrix control\nPress 9 to quit:\n");
		scanf("%d",&operation);
		switch(operation){
			case 1:
				printf("Number of rows of the first operand matrix:\n");
				scanf("%d",&r1);
				printf("Number of columns of the first operand matrix:\n");
				scanf("%d",&c1);
				dA=(double*)malloc(r1*c1*sizeof(double));
				printf("Content of the first operand matrix:\n");
				for(i=0;i<r1;i++){
					for(j=0;j<c1;j++){
						scanf("%lf",&dA(i,j));
					}
				}
				printf("Number of rows of the second operand matrix:\n");
				scanf("%d",&r2);
				printf("Number of columns of the second operand matrix:\n");
				scanf("%d",&c2);
				if(r1==r2&&c1==c2){
					dB=(double*)malloc(r2*c2*sizeof(double));
					printf("Content of the second operand matrix:\n");
					for(i=0;i<r2;i++){
						for(j=0;j<c2;j++){
							scanf("%lf",&dB(i,j));
						}
					}
					dC=(double*)malloc(r1*c1*sizeof(double));
					mat_add(r1,c1,dA,dB,dC);
					mat_display(r1,c1,dC);
				}
				else{
					printf("error! Row and column numbers must be same!\n");
				}
				return operation;
			case 2:
				printf("Number of rows of the first operand matrix:\n");
				scanf("%d",&r1);
				printf("Number of columns of the first operand matrix:\n");
				scanf("%d",&c1);
				dA=(double*)malloc(r1*c1*sizeof(double));
				printf("Content of the first operand matrix:\n");
				for(i=0;i<r1;i++){
					for(j=0;j<c1;j++){
						scanf("%lf",&dA(i,j));
					}
				}
				printf("Number of rows of the second operand matrix:\n");
				scanf("%d",&r2);
				printf("Number of columns of the second operand matrix:\n");
				scanf("%d",&c2);
				if(c1==r2){
					dB=(double*)malloc(r2*c2*sizeof(double));
					dC=(double*)malloc(r1*c2*sizeof(double));
					printf("Content of the second operand matrix:\n");
					for(i=0;i<r2;i++){
						for(j=0;j<c2;j++){
							scanf("%lf",&dB(i,j));
						}
					}
					mat_mlt(r1,c1,c2,dA,dB,dC);
					mat_display(r1,c2,dC);
				}
				else{
					printf("error! Row and column size are not suitable for multiplication!\n");
				}
				return operation;
			case 3:
				printf("Number of rows of the first operand matrix:\n");
				scanf("%d",&r1);
				printf("Number of columns of the first operand matrix:\n");
				scanf("%d",&c1);
				dA=(double*)malloc(r1*c1*sizeof(double));
				if(r1==c1){
					dB=(double*)malloc(r1*c1*sizeof(double));
					dC=(double*)malloc(r1*c1*sizeof(double));
					printf("Content of the first operand matrix:\n");
					for(i=0;i<r1;i++){
						for(j=0;j<c1;j++){
							scanf("%lf",&dA(i,j));
						}
					}	
					mat_trnsps(r1,c1,dA,dC);
					mat_display(r1,c1,dC);
				}
				else{
					printf("error! Matirx is not suitable to perform transpose!");
				}
				return operation;
			case 4:
				printf("Number of rows of the first operand matrix:\n");
				scanf("%d",&r1);
				printf("Number of columns of the first operand matrix:\n");
				scanf("%d",&c1);
				if(r1==c1){
					dB=(double*)malloc(r1*c1*sizeof(double));
					dC=(double*)malloc(r1*c1*sizeof(double));
					printf("Content of the first operand matrix:\n");
					for(i=0;i<r1;i++){
						for(j=0;j<c1;j++){
							scanf("%lf",&dA(i,j));
						}
					}	
					mat_trnsps(r1,c1,dA,dB);
					if(is_mat_equal(r1,c1,dA,dB) > 0){
						printf("symmetric");
					}
					else{
						printf("not symmetric");
					}
				}
				else{
					printf("error! Row and column numbers must be same!");
				}
				return operation;
		}
	}
	printf("Goodbye!");
	return 0;
}

























