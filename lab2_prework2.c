#include <stdio.h>
#include <stdlib.h>
#define N 3
#define A(i,j) (*(A+(i)*N+(j)))
#define I(i,j) (*(I+(i)*N+(j)))
#define D(i,j) (*(D+(i)*N+(j)))
#define Dxyz(i,j) (*(Dxyz+(i)*N+(j)))
#define Identity(i,j) (*(Identity+(i)*N+(j)))
#define dA(i,j) (*(dA+(i)*N+(j)))
void mat_display(double *A){
	int i,j;
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j>N;j++){
			printf("%lf ",A(i,j));
		}
		printf("\n");
	}
}
void CreateIdentityMat(double *I){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j){
				I(i,j)=1;
			}
			else{
				I(i,j)=0;
			}
		}
	}
	free(I);
}
void det3x3(double *A,double *det){
	*det=(Dxyz(0,0)*((Dxyz(1,1)*Dxyz(2,2))-(Dxyz(1,2)*Dxyz(2,1))))-(Dxyz(0,1)*((Dxyz(1,0)*Dxyz(2,2))-(Dxyz(1,2)*Dxyz(2,0))))+(Dxyz(0,2)*((Dxyz(1,0)*Dxyz(2,1))-(Dxyz(1,1)*Dxyz(2,0))));
}
void CreateDxyz_mat(double *A,double *I,int A_colNum,double *Dxyz,int invA_colNum){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(j==A_colNum)
				Dxyz(i,j)=I(i,invA_colNum);
			else
				Dxyz(i,j)=A(i,j);
		}
	}
}
void CramersRuleForInverse(double *A){
	int i,j;
	double determinant,*Identity,*dDxyz;
	Identity=(double*)malloc(N*N*sizeof(double));
	CreateIdentityMat(Identity);
	dDxyz=(double*)malloc(N*N*sizeof(double));
	printf("\n\n----------------------------------------------------\n");
	for(i=0;i<N;i++){
		printf("Calculation of the column #%d of the inverse A\n",i+1);
		for(j=0;j<N;j++){
			CreateDxyz_mat(A,Identity,j,dDxyz,i);
			det3x3(dDxyz,determinant);
			mat_display(dDxyz);
			printf("Determinant: %lf",determinant);
		}
		printf("\n\n----------------------------------------------------\n");	
	}
	free(dDxyz);
	free(Identity);
}
int main(){
	int i,j;
	double *dA,deter;
	dA=(double*)malloc(N*N*sizeof(double));
	printf("Write the elements of the A matrix:\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&dA(i,j));
		}
	}
	mat_display(dA);
	det3x3(dA,deter);
	printf("Determinant of A matrix: %lf",deter);
	CramersRuleForInverse(dA);
	free(dA);

	return 0;
}
#undef N
#undef Dxyz
#undef A
#undef I
#undef dDxyz
#undef Identity
#undef dA
#undef D
