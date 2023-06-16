#include <stdio.h>

extern int some; //gives linker error "undefined reference as some is not declared in this file or in other file in same directory.

void foo();

int Main() //Gives linker error as main is not found
{
	a = 3; //syntax error
	for(int i=0;i<5); //Syntax error as another ; is missing 
	int x = 3;
	int y = 5;
	if(x = 4)//logical error
	{
		printf("Do something");
	}
	x * y = 5; //semantic error lvalue required
	int arr[3] = {2,3,4};
	for(int i=0;i<=3;i++) //Semantic error as we are trying to access more than allocated memory
	{
		printf("%d\n",arr[i]);
	// syntax error as there is no '}'

	x = 3/0; //runtime error divide by zero
	int *ptr = (int*)0;
	*ptr = 20; //Runtime error. Segmentation fault
	
	foo(); //Gives linker error as foo definition is not found
}	

