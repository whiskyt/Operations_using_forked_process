#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main() // main
{
	char input[6]; // char array to take in user input
	while(1) // will run forever
	{
		printf("Enter your first number a space character,then the second followed by the operation you wish to use. ie '+' or '-' :");
		fgets(input,11,stdin); // takes user input into array
		//printf("you typed %s\n",input);
		pid_t pid;
		int status;

		if((pid = fork())<0) // if fork failed
		{
			printf("Failed to fork process\n");
          		exit(1);		
		}
		if(pid == 0) // fork successful
		{
			int ret = execl("./server","/server",&input[0],&input[2],&input[4], NULL);
			if(ret != -1) // if execl successful 
				exit((unsigned) execl("./server","/server",&input[0],&input[2],&input[4], NULL)); // calling server program with terminal arguements as arguements, returns server output
			else // execl failed
			{
			printf("Failed execl ... ret = %d\n",ret);
			exit(1);
			}
		}
		printf("Parent waiting for child process..\n");
		wait(&status);
		if(WIFEXITED(status)) // waiting for forked process
			printf("servers solution : %d\n",(unsigned)WEXITSTATUS(status)); // prints result
		else
			printf("Child did not terminate with exit\n");
	}
} 
