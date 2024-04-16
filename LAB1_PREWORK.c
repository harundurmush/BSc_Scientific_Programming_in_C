#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define A(I,J) (*(a + (I)*(n) + (J)))
#define B(I,J) (*(b + (I)*(n) + (J)))
#define WORK(I,J) (*(work + (I)*(n+1) + (J)))
#define WORK2(I,J) (*(work2 + (I)*n + (J)))

void simple_gauss( double *a, double b[], double *work, double x[], int n){
		double m;
		int i,j,k;
			
		for(i=0; i<n;i++){
			for(j=0; j<n; j++)
				WORK(i,j) = A(i,j);
			WORK(i,n) = b[i];
		}
		
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				if( j != i){
					m = WORK(j,i)/ WORK(i,i);
					for(k=0; k<=n; k++)
						WORK(j,k) -= m*WORK(i,k);
				}
		for(i=0; i<n; i++)
			x[i] = WORK(i,n) / WORK(i,i);	
	}
int gauss_jordan( double *a, double b[], double *work, double x[], int n, double tol){
	double m, max, temp;
	int i,j,k,swap;
	for(i=0; i<n;i++){
			for(j=0; j<n; j++)
				WORK(i,j) = A(i,j);
			WORK(i,n) = b[i];
		}
	for(i=0; i<n;i++){
		max = -1.0;
		for(k=i; k<n; k++)
			if(fabs(WORK(k,i)) > max){
				max = fabs(WORK(k,i));
				swap = k;
			}
		if(max <= tol)
			return(FALSE);
		if(swap != i)
			for(k=i; k<=n; k++){
				temp = WORK(i,k);
				WORK(i,k) = WORK(swap,k);
				WORK(swap,k) = temp;
			}
		for(j=0; j<n; j++)
				if( j != i){
					m = WORK(j,i)/ WORK(i,i);
					for(k=i; k<=n; k++)
						WORK(j,k) -= m*WORK(i,k);
				}
			
	}
	for(i=0; i<n;i++)
		x[i] = WORK(i,n)/WORK(i,i);
	return(TRUE);
}


int main (){
	double coeff[3][3] = { {2,3,5}, {1,2,4}, {4,7,3} };
	double rhs[3] = {10,5,15};
	double place[3][4];
	double answer[3];
	int i,j;
	//simple_gauss(&coeff[0][0], rhs, &place[0][0], answer, 3);
	if(gauss_jordan(&coeff[0][0], rhs, &place[0][0], answer, 3, .00001)){
		printf("Solution is: %.3f %.3f %.3f\n", answer[0], answer[1], answer[2]);
	for(i=0; i<3;i++){
			for(j=0; j<3; j++)
				printf("%.3f\t", place[i][j]);
			printf("\n");
			}
	}	
	else
		printf("No solution found\n");
	
	
	return 0;
}
	#undef A
	#undef WORK
	#undef B
	#undef WORK2
	

