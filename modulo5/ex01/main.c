#include <stdio.h>

union union_u1{
	char vec[32];
	float a;
	int b;
} u;

struct struct_s1{
	int b;
	char vec[32];
	float a;
	
} s;

struct s2{
	char a[3];
	long long d;
	int c;
} l;

typedef struct
{

    unsigned int notas;

}aluno;

int main(void){
	
	printf("union size: %d\n", (int) sizeof(u));
	printf("struct size: %d\n", (int) sizeof(l));
	
	/*
	 * Unions use the same memory location for all variables, 
	 * 32 is the largest size of the 3 variables,
	 * so the union will have size of 32.
	 * 
	 * Each element of struct have their own memory,
	 * in this case 32 + 4 + 4, therefore 40.
	 * 
	*/ 
	
}