#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[]){
	for(int i=0;i<80;i++){
		for(int j=0;j<80;j++){
			if(fabs(i-(j-3)/2)<1 && i<=23 && i>=1 )
				printf("- ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	
}
