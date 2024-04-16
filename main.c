#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 3
#define Dxyz(I,J) (*(Dxyz+(I)*N+(J)))
#define a(I,J) (*(A+(I)*N+(J)))
#define b(I,J) (*(B+(I)*N+(J)))
#define u(I,J) (*(U+(I)*N+(J)))

/*
#define A(I,J) (*(a+(I)*3+(J)))
#define dA(I,J) (*(dA+(I)*3+(J)))
*/

/*
void minor(double *a, int row, int col){
	
	double n[2][2];
	int x=0, y=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i!=row && j!=col){
				n[x][y]=A(i,j);
				y++;
			}
		}
		if(y==2){
			y=0;
			x=1;
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("%lf  ",n[i][j]);
		}
		printf("\n");
	}
	
}
*/

void identity(double *U){
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j){
				u(i,j)=1;
			}
			else{
				u(i,j)=0;
			}
		}
	}
}
void deter(double *A, double det){
	
	double h=(a(0,0)*((a(1,1)*a(2,2))-(a(1,2)*a(2,1))))-(a(0,1)*((a(1,0)*a(2,2))-(a(1,2)*a(2,0))))+(a(0,2)*((a(1,0)*a(2,2))-(a(1,2)*a(2,0))));
	det=h;
	printf("determinant fonk===%lf\n",h);
}
void create(double *B, double *U, int Acol, double *Dxyz, int invAcol){
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(j==Acol){
				Dxyz(i,j)=u(i,invAcol);
			}
			else{
				Dxyz(i,j)=b(i,j);
			}
		}
	}
}
void cramer(double *A){
	double determinant;
	printf("elements of A matrix:");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
		scanf("%lf",&a(i,j));
		
		}
	}
	deter(A,determinant);

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%lf  ",a(i,j));
		}
		printf("\n");
	}
	
	printf("determinant of A: %lf\n",determinant);
}


int main() {
	
	
	double *A;
	A=(double*)malloc(N*N*sizeof(double));
	cramer(&a(0,0));
	
	
	
	
	/*
	//minor
	double *dA;
	int r,c;
	scanf("%d",&r);
	scanf("%d",&c);	
	dA=(double*)malloc(3*3*sizeof(double));
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%lf",&dA(i,j));
		}
	}
	minor(dA,r,c);
	*/
	
	return 0;
	free(A);
}

#undef a
#undef b
#undef u
#undef Dxyz
