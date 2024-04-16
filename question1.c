#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 3
//number of error would be bigger if h was 0.1, so result would be less precisely.
//Decreasing the value of h makes result more accurate.
struct Node{
	char diff_method[N];
	float n_diff;
	float a_diff;
	float error;
	struct Node *nextPtr;
};
typedef struct Node Num_Diff;
float f(float x){
	return pow((x-3),2)+1;
}
float Derivative(float x){
	return 2*(x-3);
}
float Forward_Diff(float x){
	return (f(x+0.001)-f(x))/0.001;
}
float Backward_Diff(float x){
	return (f(x)-f(x-0.001))/0.001;
}
float Centered_Diff(float x){
	return (f(x+0.001)-f(x-0.001))/0.002;
}
void print_node(Num_Diff *y){
	printf("%s\t",y->diff_method);
	printf("%lf\t",y->n_diff);
	printf("%lf\t",y->a_diff);
	printf("%lf",y->error);
	printf("\n");
}
float main(){
	double x;
	printf("Enter function variable 'x'\n");
	scanf("%lf",&x);
	int i;
	Num_Diff *mainNode;
	printf("\nNumerical Derivative Method\tNumerical Solution\tAnalytic Solution\tError(%c)\n",'%');
	printf("---------------------------\t------------------\t-----------------\t--------\n");
	mainNode = (Num_Diff*)malloc(sizeof(Num_Diff));
	mainNode->a_diff=Derivative(x);
	for(i=0;i<N;i++){
		if(i==0){
			mainNode->n_diff=Forward_Diff(x);
			strcpy(mainNode->diff_method,"Forward Difference");
		}
		else if(i==1){
			mainNode->n_diff=Backward_Diff(x);
			strcpy(mainNode->diff_method,"Backward Difference");
		}
		else if(i==2){
			mainNode->n_diff=Centered_Diff(x);
			strcpy(mainNode->diff_method,"Centered Difference");
		}
		mainNode->error=(fabs(mainNode->n_diff-mainNode->a_diff)/mainNode->a_diff)*100;
		mainNode->nextPtr=mainNode;
		print_node(mainNode);
	}
	/*printf("\nNumerical Derivative Method\tNumerical Solution\tAnalytic Solution\tError(%c)\n",'%');
	printf("---------------------------\t------------------\t-----------------\t--------\n");
	printf("Forward Difference\t%lf\t%lf\t%lf\n",Forward_Diff(x),Derivative(x),(fabs(Derivative(x)-Forward_Diff(x))/Derivative(x))*100);
	printf("Backward Difference\t%lf\t%lf\t%lf\n",Backward_Diff(x),Derivative(x),(fabs(Derivative(x)-Backward_Diff(x))/Derivative(x))*100);
	printf("Centered Difference\t%lf\t%lf\t%lf\n",Centered_Diff(x),Derivative(x),(fabs(Derivative(x)-Centered_Diff(x))/Derivative(x))*100);*/
	return 0;
}
