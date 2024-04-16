#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	char a;
	int b;
	char c;
	int d;
	char e;
	int g;
	a= argv[1][0];
	b= a - '0' ;
	c= argv[2][0];
	d= c - '0' ;
	e= argv[3][0];
	g= e - '0' ;
	printf("%d",argc);
	printf("%c %s %s %s %d\n",argv[1][0],argv[1],argv[2],argv[3],b);
	
	for(int i=0;i<80;i++){
		for(int j=0;j<80;j++){
			if(fabs((i-b)*(i-b)+(j-d)*(j-d))<=g*g)
				printf("- ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	
	
	
}
