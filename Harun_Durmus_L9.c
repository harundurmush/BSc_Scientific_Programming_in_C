#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
struct measurement{
	char parameter[N];
	char unit[N];
	int num;
	struct measurement *nextPtr;
};
typedef struct measurement measurement;
measurement *head=NULL;
int c=0;
void first_node();
void insert_node(measurement *x,char q[N],char u[N]);
void print_node(measurement *y);
measurement *delete_node(measurement *z,int number);
void main(){
	measurement *main;
	int operation=!0;
	char a[N],b[N];
	while(operation!=0){
		printf("Choose an operation\n1. Add a measurement\n2. Delete a measurement\n");
		scanf("%d",&operation);
		if(operation==1){
			first_node();
			printf("Enter the Electrical Measurement Parameter\n");
			scanf("%s",&a);
			printf("Enter the Parameter Unit\n");
			scanf("%s",&b);
			insert_node(main,a,b);
			print_node(main);
		}
		else if(operation==2){
			
		}
	}
}
void first_node(){
	head = (measurement*)malloc(sizeof(measurement));
	head->nextPtr=NULL;
}
void insert_node(measurement *x,char q[N],char u[N]){
	x->nextPtr = (measurement*)malloc(sizeof(measurement));
	strcpy(x->parameter,q);
	strcpy(x->unit,u);
}
void print_node(measurement *y){
	y->nextPtr = (measurement*)malloc(sizeof(char));
	printf("\t%d\t%s\t\t%s\n",y->num,y->parameter,y->unit);
	c++;
}
measurement *delete_node(measurement *z,int number){
	int i=0;
	measurement *tmp;
	measurement *iter;
	if(z->nextPtr == head){
		tmp = head;
		free(tmp);
	}
	else if(z->nextPtr == iter);
}








