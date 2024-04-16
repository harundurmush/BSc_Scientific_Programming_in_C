#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[]){
	for(int i=40;i>0;i--){
		for(int j=0;j<40;j++){
			if(fabs((i-20)*(i-20)+(j-30)*(j-30))<=25)
				printf("- ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	
}
