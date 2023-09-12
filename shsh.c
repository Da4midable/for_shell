#include "main.h"


int main(int argc, char **argv)
{
	/*int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i++]);
	}*/


	/*char *cmd = "./child_program";
	char *args[] = {"./child_program", "a", "b", "c", NULL};
	char *env[] = {"MY_COLOR=BLUE," "PARENT_NAME=I_AM_THE_PARENT", NULL};*/

	/*char *cmd = "/bin/ls";
	char *args[] = {"/bin/ls", "-la", NULL};*/

	char *args[] = {"./child_program", NULL};
	char *env[] = {"MY_COLOR=BLUE," "PARENT_NAME=I_AM_THE_PARENT", NULL};


	printf("> main program: start\n");

	execve(
		args[0],
		args,
		NULL
	);

	printf("> program: end\n");

	return (0);

}