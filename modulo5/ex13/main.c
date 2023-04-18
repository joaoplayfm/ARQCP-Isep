#include<stdio.h>
#include <stdlib.h>
#include"asm.h"


int main(){
	int **matrix;
	matrix = new_matrix(4 , 4);

	for(int lines = 0; lines < 4; lines++)
	{
		for(int collums = 0; collums < 4; collums++)
		{
			*(*(matrix + lines) + collums) = lines + 2 + collums + 3;
		}
	}
	
	int res = count_odd_matrix (matrix, 4, 4);
	
	printf("\n|---|\n");
	printf("| %d |",res);
	printf("\n|---|\n");
	
	return 0;
}
