// this is to be called by forked process in client program

#include <stdio.h>
#include <stdlib.h>


int operation(char* a, char *b, char *c) // function that takes terminal inputed arguements and returns result of additon or subtraction of the two numbers 
{
	int result;
	int num1 = atoi(a);// converts char* to int
	int num2 = atoi(b);
	//printf("num1 is %d and num2 is %d\n",num1,num2);
	
	if(*c == '+')
		result = num1 + num2;
	else
		result = (unsigned)num1 - (unsigned)num2;
	//printf("result is %d\n",result);
	return result;

}

int main(int argc, char *argv[]) //main
{
	unsigned int result = operation(argv[1],argv[2],argv[3]); 
	//printf("the result is %d\n",result);
	return result;
}

